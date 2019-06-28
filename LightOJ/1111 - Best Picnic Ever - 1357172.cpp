#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(x) scanf("%lld", &x)
vector <ll> g[1009];
ll city[109];
bool vis[109][1009];
void dfs(ll u, ll id)
{
    vis[id][u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(vis[id][nd])
            continue;
          dfs(nd, id);
    }
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        ll k, n, m;
        sc(k), sc(n), sc(m);
          for(ll i = 1; i <= k; i++)
            sc(city[i]);
          for(ll i = 1; i <= m; i++) {
            ll u, v;
            sc(u), sc(v);
            g[u].push_back(v);
        }
          for(ll i = 1; i <= k; i++)
            dfs(city[i], i);
          ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            bool chk = 1;
            for(ll j = 1; j <= k; j++)
                if(vis[j][i] == 0) {
                    chk = 0;
                    break;
                }
              if(chk)
                ans++;
        }
          printf("Case %lld: %lld\n", ++cs, ans);
          for(ll i = 0; i  <= n; i++)
            g[i].clear();
    }
      return 0;
}
 
