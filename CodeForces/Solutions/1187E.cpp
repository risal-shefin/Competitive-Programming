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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;
vector <ll> g[sz];
ll sub[sz], dp[sz], ans = 0;

void dfs(ll u, ll p)
{
    sub[u] = 1, dp[u] = 0;

    for(ll v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u);
        dp[u] += dp[v];
        sub[u] += sub[v];
    }

    dp[u] += sub[u];
}

void change_root(ll from, ll to)
{
    dp[from] -= dp[to];
    dp[from] -= sub[to];
    sub[from] -= sub[to];

    dp[to] += dp[from];
    dp[to] += sub[from];
    sub[to] += sub[from];
}

void reroot(ll u, ll p)
{
    ans = max(ans, dp[u]);

    for(ll v : g[u]) {
        if(v == p)
            continue;

        change_root(u, v);

        reroot(v, u);

        change_root(v, u);
    }
}

int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1);
    reroot(1, -1);

    pf("%lld\n", ans);

    return 0;
}