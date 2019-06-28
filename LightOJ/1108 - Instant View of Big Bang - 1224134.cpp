#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> graph[1010], cost[1010];
ll dist[1010];
bool visit[1010];
void dfs(ll u)
{
    if(visit[u])
        return;
    visit[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++)
        dfs( graph[u][i] );
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 1005; i++) {
            cost[i].clear();
            graph[i].clear();
            dist[i] = 0;
            visit[i] = 0;
        }
          ll n, m;
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= m; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            graph[v].pb(u);
            cost[v].pb(c);
        }
          for(ll i = 1; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                for(ll k = 0; k < graph[j].size(); k++) {
                    ll u = j, v = graph[j][k], c = cost[j][k];
                    if(dist[ v ] > dist[u] + c) {
                        dist[ v ] = dist[u] + c;
                    }
                }
            }
        }
          for(ll j = 0; j < n; j++)
        {
            for(ll k = 0; k < graph[j].size(); k++)
            {
                ll u = j, v = graph[j][k], c = cost[j][k];
                //cout << dist[v] << "  " << u << "  " << c << endl;
                if(dist[ v ] > dist[u] + c)
                {
                    dfs(u);
                }
            }
        }
          vector <ll> ans;
        for(ll j = 0; j < n; j++) {
            if(visit[j]) {
                //cout << j << endl;
                ans.pb(j);
            }
        }
            printf("Case %lld:", ++caseno);
        for(ll i = 0; i < ans.size(); i++) {
            printf(" ");
            printf("%lld", ans[i]);
        }
          if(ans.size() == 0)
            printf(" impossible");
        printf("\n");
      }
      return 0;
}
 
