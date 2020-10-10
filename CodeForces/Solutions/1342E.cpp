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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll mod = 998244353, sz = 2e5 + 10;

ll fastPow(ll x, ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % mod;
        x = (x*x) % mod;
        n >>= 1;
    }
    return ret % mod;
}

ll fact[sz], inv[sz];

ll nCr(ll n, ll r) {
    ll hor = (inv[r] * inv[n-r]) % mod;
    return (fact[n] * hor) % mod;
}

int main()
{
    fact[0] = 1;
    for1(i, sz-1) fact[i] = (fact[i-1] * i) % mod;

    inv[sz-1] = fastPow(fact[sz-1], mod-2);
    for(ll i = sz - 2; i >= 0; i--)
        inv[i] = (inv[i+1] * (i+1)) % mod;

    ll n, k;
    cin >> n >> k;

    if(k >= n) {
        cout << 0 << EL;
        return 0;
    }

    ll tot = 0, col = n-k;
    for(ll blank = 0; blank < col; blank++) {

        ll exist = col - blank;
        ll way = (nCr(col, blank) * fastPow(exist, n)) % mod;

        if(blank & 1)
            tot = (tot-way) % mod;
        else
            tot = (tot + way) % mod;

        if(tot < 0) tot += mod;
    }
    tot = (nCr(n, col) * tot) % mod;

    if(k > 0) tot = (tot * 2) % mod;
    cout << tot << endl;

    return 0;
}