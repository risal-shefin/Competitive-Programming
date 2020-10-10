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
#define inf (1LL << 61)
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

const ll MAX_N = 1e5+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
char s[MAX_N];  // 1-indexed
ll pw1[MAX_N], pw2[MAX_N], slen;

void pw_calc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

struct Hash {
    ll h1[MAX_N], h2[MAX_N];

    void init() {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= slen; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % mod;
            h2[i] = (h2[i-1] * base2 + s[i]) % mod;
        }
    }

    inline ll hashVal(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }
} fw1, fw2;

/* call pw_calc() for calculating powers less than MAX_N
 * slen = strlen(s+1);   --> string length
 * fw.init() will calculate the double hashes
 * fw.hashVal(l,r) will return [l,,r] merged double hash value
*/

const ll MOD = 1e9 + 7, sz = MAX_N;
ll wayEnd[sz], way[sz], sumOfWay[sz], lent, lens;

int main()
{
    pw_calc();

    scanf("%s", s+1);
    lens = slen = strlen(s+1);
    fw1.init();

    scanf("%s", s+1);
    lent = slen = strlen(s+1);
    fw2.init();

    ll thash = fw2.hashVal(1, lent);

    for1(i, lens) {
        ll start = i - lent + 1;

        if(start >= 1 && fw1.hashVal(start, i) == thash)
            wayEnd[i] = (start + sumOfWay[start-1]) % MOD;
        else
            wayEnd[i] = wayEnd[i-1];

        way[i] = (way[i-1] + wayEnd[i]) % MOD;
        sumOfWay[i] = (sumOfWay[i-1] + way[i]) % MOD;
    }

    cout << way[lens] << EL;

    return 0;
}