#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dist[109];
vector <ll> graph[109], cost[109];
struct node {
    ll u;
    ll c;
    node(ll _u, ll _c) {
        u = _u;
        c = _c;
    }
};
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= n; i++) {
            dist[i] = 2e18;
            graph[i].clear();
            cost[i].clear();
        }
          for(ll i = 1; i <= m; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
              graph[u].pb(v);
            graph[v].pb(u);
              cost[u].pb(c);
            cost[v].pb(c);
        }
          queue <node> pq;
        pq.push( node(1, 0) );
        dist[1] = 0;
        while(!pq.empty()) {
            node tmp = pq.front();
            pq.pop();
              ll u = tmp.u;
            ll c = tmp.c;
              if(dist[u] != c)
                continue;
              for(ll i = 0; i < graph[u].size(); i++) {
                ll nd = graph[u][i];
                ll cst = cost[u][i];
                  if(dist[nd] > c + cst) {
                    dist[nd] = c + cst;
                    pq.push(node(nd, dist[nd]) );
                }
            }
        }
          printf("Case %lld: ", ++caseno);
        if(dist[n] == 2e18)
            printf("Impossible\n");
        else
            printf("%lld\n", dist[n]);
    }
      return 0;
}
 
