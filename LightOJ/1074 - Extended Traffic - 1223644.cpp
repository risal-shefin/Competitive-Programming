#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll cst[205], dist[205];
struct Edge {
    ll u, v, c;
};
vector <Edge> graph;
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 1; i <= 202; i++) {
            dist[i] = 1e18;
        }
        ll n, m, u, v;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &cst[i] );
          scanf("%lld", &m);
        for(ll i = 1; i <= m; i++) {
            scanf("%lld %lld", &u, &v);
            Edge tmp;
            tmp.u = u, tmp.v = v, tmp.c = (cst[v] - cst[u]) * (cst[v] - cst[u]) * (cst[v] - cst[u]);
            graph.push_back(tmp);
            tmp.v = u, tmp.u = v, tmp.c = (cst[u] - cst[v]) * (cst[u] - cst[v]) * (cst[u] - cst[v]);
            //graph.pb(tmp);
        }
          dist[1] = 0;
        for(ll i = 1; i < n; i++) {
            for(ll j = 0; j < graph.size(); j++) {
                Edge e = graph[j];
                if(dist[e.v] > e.c + dist[e.u])
                    dist[e.v] = e.c + dist[e.u];
            }
        }
          printf("Case %lld:\n", ++caseno);
        ll qr, nd;
        scanf("%lld", &qr);
        for(ll i = 1; i <= qr; i++) {
            scanf("%lld", &nd);
            if(dist[nd] < 3 || dist[nd] == 1e18)
                printf("?\n");
            else
                printf("%lld\n", dist[nd]);
        }
          graph.clear();
    }
      return 0;
}
 
