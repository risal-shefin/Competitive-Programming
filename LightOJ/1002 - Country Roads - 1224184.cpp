#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> graph[510], cost[510];
struct node {
    ll v, c;
    node(ll _v, ll _c) {
        v = _v;
        c = _c;
    }
};
bool operator <(node a, node b)
{
    return a.c < b.c;
}
ll dist[510];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 505; i++) {
            dist[i] = 1e18;
            graph[i].clear();
            cost[i].clear();
        }
          ll n, m;
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= m; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
              graph[u].pb(v);
            cost[u].pb(c);
            graph[v].pb(u);
            cost[v].pb(c);
        }
          ll h;
        scanf("%lld", &h);
        dist[h] = 0;
        priority_queue <node> pq;
        pq.push( node(h, 0) );
          while(!pq.empty()) {
            node u = pq.top();
            pq.pop();
              if(dist[u.v] != u.c)
                continue;
              for(ll i = 0; i < graph[u.v].size(); i++) {
                ll nd = graph[u.v][i];
                ll cst = max(cost[u.v][i], u.c);
                if(dist[nd] > cst) {
                    dist[nd] = cst;
                    pq.push( node(nd, cst) );
                }
            }
        }
          printf("Case %lld:\n", ++caseno);
        for(ll i = 0; i < n; i++) {
            if(dist[i] == 1e18) {
                printf("Impossible\n");
                continue;
            }
            printf("%lld\n", dist[i]);
        }
    }
      return 0;
}
 
