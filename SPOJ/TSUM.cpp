// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/***
   * Multiply (7x^2 + 8x^1 + 9x^0) with (6x^1 + 5x^0)
   * ans = 42x^3 + 83x^2 + 94x^1 + 45x^0
   * A = {9, 8, 7}
   * B = {5, 6}
   * V = multiply(A,B)
   * V = {45, 94, 83, 42}
***/

/*** Tricks
   * Use vector < bool > if you need to check only the status of the sum
   * Use bigmod if the power is over same polynomial && power is big
   * Use long double if you need more precision
   * Use long long for overflow
***/
typedef vector <ll> vi;
const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

void fft(vector<cd> & a, bool invert = 0)

{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void ifft(vector <cd> & p)

{
    fft(p, 1);
}

vi multiply(vi const& a, vi const& b)
{

    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    ifft(fa);

    vi result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    return result;
}

const ll MAX_N = 2e4 + 10, offset = 2e4, sz = 4e4 + 10;
vi num1, num2, res1, res2;

ll ara[sz], cntDouble[2*MAX_N + 2*offset], cntTriple[3*MAX_N + 3*offset];

int main()
{
    num1.resize(MAX_N + offset, 0), num2.resize(2*MAX_N + 2*offset, 0);

    ll n;
    cin >> n;

    for1(i, n) {
        sl(ara[i]);
        ara[i] += offset;

        ll doubl = 2 * ara[i], tripl = 3*ara[i];

        num1[ara[i]]++;
        num2[doubl]++;

        cntDouble[doubl]++, cntTriple[tripl]++;
    }

    res1 = multiply(num1, num1);

    for0(i, res1.size()) {

        if(i < 2*MAX_N + 2*offset)
            res1[i] -= cntDouble[i];

        assert(res1[i] % 2 == 0);
        res1[i] /= 2;
    }

    //cout << res1[1] << " || " << res1[2] << endl;
    res1 = multiply(res1, num1);

    res2 = multiply(num2, num1);

    for0(i, res2.size()) {
        if(i < 3*MAX_N + 3*offset)
            res2[i] -= cntTriple[i];
    }

    for0(i, res1.size()) {
        if(i >= res2.size()) break;

        assert(res1[i] >= res2[i]);
        res1[i] -= res2[i];
    }

    for0(i, res1.size()) {
        if(res1[i])
            pf("%lld : %lld\n", i-3*offset, res1[i] / 3);
    }

    return 0;
