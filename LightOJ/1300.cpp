#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector <ll> g[10009], indx[10009], mark[10009];
bool vis[10009];
ll low[10009], start[10009], TM = 0, col[10009];

void clr() {
    for(ll i = 0; i < 10002; i++) {
        g[i].clear(), indx[i].clear(), mark[i].clear();
        vis[i] = 0;
        col[i] = 0;
    }
    TM = 0;
}

void artdfs(ll u, ll p)

{
    low[u] = start[u] = TM++;
    vis[u] = 1;
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
                mark[v][ indx[u][i] ] = 1;
            }
        }
    }
}

ll bicolor(ll s)

{
    queue <ll> q;
    q.push(s);
    col[s] = 1;
    bool odd = 0;
    ll sz = 1;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll i = 0; i < g[u].size(); i++) {
            ll v = g[u][i];
            if(mark[u][i])
                continue;

            if(col[v] != 0) {
                if(col[v] == col[u]) odd = 1;
            }
            else {
                if(col[u] == 1) col[v] = 2;
                else col[v] = 1;

                q.push(v);
                sz++;
            }
        }
    }

    if(odd) return sz;    // Non-bicolorable cycle has odd length
    else return 0;
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

            indx[u].pb(mark[v].size());
            indx[v].pb(mark[u].size());
            mark[u].pb(0);
            mark[v].pb(0);
        }

        for(ll i = 0; i < n; i++) {
            if(vis[i])
                continue;

            artdfs(i, -1);
        }

        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            if(col[i])
                continue;

            ans += bicolor(i);
        }

        printf("Case %lld: %lld\n", ++cs, ans);

        clr();
    }

    return 0;
}
