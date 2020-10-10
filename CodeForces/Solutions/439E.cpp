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

const ll sz = 1e5 + 10, mod = 1e9 + 7;
vector <ll> dv[sz];
ll dp[sz], fact[sz], inv[sz], totalWay[sz];
unordered_map <int, int> ret[sz];

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n) {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

inline ll starsBars(ll n, ll k)
{
    n--, k--;
    ll den = (inv[k] * inv[n-k]) % mod;
    return (fact[n] * den) % mod;
}

ll solve(ll n, ll f)
{
    if(n < f) return 0;

    if(dp[n] != -1) return dp[n];

    ll way = starsBars(n, f);

    for(ll &g : dv[n]) {
        way -= solve(n/g, f);
        if(way < 0) way += mod;
    }

    return dp[n] = way;
}

int main()
{
    for(ll i = 2; i < sz; i++)
        for(ll j = i+i; j < sz; j += i)
            dv[j].pb(i);

    fact[0] = 1;
    for1(i, sz-1) fact[i] = (fact[i-1] * i) % mod;

    inv[sz-1] = fastPow(fact[sz-1], mod-2, mod);
    rep0(i, sz-1) inv[i] = (inv[i+1] * (i+1)) % mod;

    ll q;
    cin >> q;

    while(q--) {
        ll n, f;
        sl(n), sl(f);

        if(f == 1) {
            if(n == 1) pf("1\n");
            else pf("0\n");

            continue;
        }

        if(ret[n].find(f) != ret[n].end()) {
            pf("%d\n", ret[n][f]);
            continue;
        }

        for(ll &d: dv[n]) dp[d] = -1;
        dp[n] = -1;

        pf("%d\n", ret[n][f] = solve(n, f));
    }

    return 0;
}