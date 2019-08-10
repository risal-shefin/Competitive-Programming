#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define pb push_back
vector <ll> g[10009], mark[10009], indx[10009];
vector <pll> bridges;
bool vis[10009];
ll low[10009], start[10009], TM = 1, scc = 0, sccOfNode[10009], cnt[10009];

void clr() {
    for(ll i = 0; i <= 10000; i++) g[i].clear(), mark[i].clear(), indx[i].clear();
    bridges.clear();
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    TM = 1, scc = 0;
}

void artdfs(ll u, ll p)

{
    vis[u] = 1;
    low[u] = start[u] = TM++;
    for(ll i = 0; i < g[u].size(); i++) {
        ll v = g[u][i];
        if(v == p)
            continue;

        if(vis[v])
            low[u] = min(low[u], start[v]);
        else {
            artdfs(v, u);
            low[u] = min(low[u], low[v]);
            if(start[u] < low[v]) {
                mark[u][i] = 1;
                bridges.push_back(pll(u, v));
            }
        }
    }
}

void dfs(ll u, ll p)

{
    vis[u] = 1;
    sccOfNode[u] = scc;
    for(ll i = 0; i < g[u].size(); i++) {
        ll v = g[u][i];
        if(v == p || mark[u][i] == 1 || mark[v][ indx[u][i] ] == 1 || vis[v])
            continue;

        dfs(v, u);
    }
}

int main()

{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);

        for(ll i = 1; i <= m; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);

            g[u].pb(v);
            g[v].pb(u);

            indx[u].pb( mark[v].size() );
            indx[v].pb( mark[u].size() );
            mark[u].pb(0);
            mark[v].pb(0);
        }

        artdfs(0, -1);

        memset(vis, 0, sizeof(vis));
        ll component = 0;
        for(ll i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1);
                scc++;
            }
        }

        for(pll p: bridges)
            cnt[ sccOfNode[p.first] ]++, cnt[ sccOfNode[p.second] ]++;

        for(ll i = 0; i < scc; i++)
            if(cnt[i] == 1) component++;

        printf("Case %lld: %lld\n", ++cs, (component + 1) / 2);

        clr();
    }

    return 0;
}

