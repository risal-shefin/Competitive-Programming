
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

const ll sz = 1e5 + 10;
vector <int> g[sz], cyc, col[2];
ll n, m, k, lev[sz], par[sz];
bool vis[sz];

void dfs(ll u, ll p, ll d)
{
    if(!cyc.empty()) return;
    col[d & 1].pb(u);

    par[u] = p, lev[u] = d, vis[u] = 1;

    ll low = -inf, cycStart = -1;
    for(int &v : g[u]) {
        if(v != p && lev[v] < d && lev[v] > low) {
            low = lev[v];
            cycStart = v;
        }
    }

    if(cycStart != -1) cyc.pb(u);
    while(cycStart != -1 && u != cycStart) {
        u = par[u];
        cyc.pb(u);
    }
    if(cycStart != -1) return;

    for(int &v : g[u]) {
        if(vis[v])
            continue;

        dfs(v, u, d+1);
    }
}

int main()
{
    cin >> n >> m >> k;
    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) lev[i] = inf;
    dfs(1, -1, 1);

    if(m == n-1) {
        pf("1\n");
        if(col[0].size() > col[1].size())
            for(int i = 0; i < (k+1)/2; i++) pf("%d ", col[0][i]);
        else
            for(int i = 0; i < (k+1)/2; i++) pf("%d ", col[1][i]);

        pn; return 0;
    }

    if(cyc.size() <= k) {
        pf("2\n%lld\n", (ll)cyc.size());
        for(int &u : cyc) pf("%d ", u);
        pn; return 0;
    }

    pf("1\n");
    for(int i = 0, j = 1; j <= (k+1)/2; i += 2, j++) pf("%d ", cyc[i]);
    pn;

    return 0;
}