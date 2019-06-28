#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> g[20009], grev[20009];
stack <ll> node;
bitset <20009> vis;
ll root[20009], in[20009], out[20009];
void dfs2(ll u)
{
    vis[u] = 1;
    for(ll i = 0; i < grev[u].size(); i++) {
        ll nd = grev[u][i];
        if(vis[nd])
            continue;
        dfs2(nd);
    }
      node.push(u);
}
void dfs(ll u, ll p)
{
    vis[u] = 1;
    root[u] = p;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(vis[nd])
            continue;
        dfs(nd, p);
    }
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
          ll n, e;
        scanf("%lld %lld", &n, &e);
          for(ll i = 1; i <= e; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            g[u].pb(v);
            grev[v].pb(u);
        }
          vis.reset();
        for(ll i = 1; i <= n; i++) {
            if(!vis[i])
                dfs2(i);
        }
          ll scc = 0;
        vis.reset();
        while(!node.empty()) {
            ll u = node.top();
            node.pop();
              if(!vis[u])
                dfs(u, ++scc);
        }
          memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for(ll i = 1; i <= n; i++) {
            for(ll j = 0; j < g[i].size(); j++) {
                if(root[i] != root[ g[i][j] ]) {
                    out[ root[i] ]++;
                    in[ root[g[i][j]] ]++;
                }
            }
            g[i].clear();
            grev[i].clear();
        }
          ll cnt1 = 0, cnt2 = 0;
        for(ll i = 1; i <= scc; i++) {
            if(in[i] == 0) cnt1++;
            if(out[i] == 0) cnt2++;
        }
          printf("Case %lld: %lld\n", ++cs, scc == 1? 0LL: max(cnt1, cnt2));
      }
    return 0;
}
 
