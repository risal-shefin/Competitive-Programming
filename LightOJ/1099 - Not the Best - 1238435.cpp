#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mn first
#define mn2 second
#define pii pair <ll, ll>
pii dist[109];
vector <ll> graph[5009], cost[5009];
struct node {
    ll u;
    ll c;
    node(ll _u, ll _c) {
        u = _u;
        c = _c;
    }
};
bool operator <(node a, node b)
{
    return a.c > b.c;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= n; i++) {
            dist[i].mn = 2e18;
            dist[i].mn2 = 2e18;
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
          priority_queue <node> pq;
        pq.push( node(1, 0) );
        dist[1].mn = 0;
        while(!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
              ll u = tmp.u;
            ll c = tmp.c;
              for(ll i = 0; i < graph[u].size(); i++) {
                ll nd = graph[u][i];
                ll cst = cost[u][i];
                  if(dist[nd].mn > c + cst) {
                    dist[nd].mn2 = dist[nd].mn;
                    dist[nd].mn = c + cst;
                    pq.push( node(nd, dist[nd].mn2) );
                    pq.push(node(nd, dist[nd].mn) );
                }
                else if(dist[nd].mn < c + cst && dist[nd].mn2 > c + cst) {
                    dist[nd].mn2 = c + cst;
                    pq.push( node(nd, dist[nd].mn2) );
                }
            }
        }
          printf("Case %lld: ", ++caseno);
        printf("%lld\n", dist[n].mn2);
    }
      return 0;
}
   
