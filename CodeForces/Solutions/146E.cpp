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
ll fact[sz], inv[sz], ara[sz];

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret % MOD;
}

inline ll nCr(ll n, ll r)
{
    if(n < r) return 0;

    ll den = (inv[r] * inv[n-r] ) % mod;
    return (fact[n] * den) % mod;
}

inline bool isLucky(ll num)
{
    while(num) {
        if(num % 10 != 4 && num % 10 != 7)
            return 0;

        num /= 10;
    }
    return 1;
}

unordered_map <int, int> ase;
vector < vector <ll> > dp;
vector <ll> way;

ll solve(ll pos, ll rest)
{
    if(pos == 0) {
        return rest == 0;
    }
    if(rest < 0)
        return 0;

    ll &ret = dp[pos][rest];
    if(ret != -1)
        return ret;

    ret = solve(pos-1, rest);
    ret += (way[pos] * solve(pos-1, rest-1)) % mod;

    if(ret >= mod) ret -= mod;

    return ret;
}

int main()
{
    fact[0] = 1;
    for1(i, sz-1) fact[i] = (fact[i-1] * i) % mod;

    inv[sz-1] = fastPow(fact[sz-1], mod-2, mod);
    rep0(i, sz-1) inv[i] = (inv[i+1] * (i+1)) % mod;

    ll n, k, unlucky = 0;
    sl(n), sl(k);

    for1(i, n) {
        sl(ara[i]);

        if(isLucky(ara[i]))
            ++ase[ ara[i] ];
        else
            unlucky++;
    }

    ll totLucky = ase.size();
    dp.resize(totLucky+1);
    way.resize(totLucky+1);

    for(ll i = 0; i <= totLucky; i++) {

        dp[i].resize(totLucky+1);

        for(ll &val : dp[i]) val = -1;
    }

    ll idx = 0;
    for(pii p : ase) way[++idx] = p.second;

    dp[totLucky][0] = 1;

    for1(i, totLucky) {
        dp[totLucky][i] = solve(totLucky, i);
    }

    ll ans = 0;

    for(ll i = 0; i <= min(k, totLucky); i++) {

        ll rest = k - i, way = nCr(unlucky, rest);

        ans += (dp[totLucky][i] * way) % mod;

        if(ans >= mod) ans -= mod;
    }

    cout << ans << EL;

    return 0;
}