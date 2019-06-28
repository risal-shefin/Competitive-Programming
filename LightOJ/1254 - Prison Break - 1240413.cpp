#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dist[105][105], cost[105];
struct node {
    ll v;
    ll w;
    node(ll _v, ll _w) {
        v = _v;
        w = _w;
    }
};
vector <node> edge[105];
struct car {
    ll u;
    ll c;
    ll fil;
    car(ll _u, ll _c, ll _f) {
        u = _u;
        c = _c;
        fil = _f;
    }
};
bool operator <(car a, car b)
{
    return a.c > b.c;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m, u, v, w;
        scanf("%lld %lld", &n, &m);
        for(ll i = 0; i < n; i++) {
            scanf("%lld", &cost[i]);
            edge[i].clear();
        }
          for(ll i = 1; i <= m; i++) {
            scanf("%lld %lld %lld", &u, &v, &w);
            edge[u].pb( node(v, w));
            edge[v].pb( node(u, w));
        }
          ll q;
        printf("Case %lld:\n", ++caseno);
        scanf("%lld", &q);
        for(ll i = 1; i <= q; i++) {
              ll ans = 1e18;
            for(ll j = 0; j < n; j++)
                for(ll k = 0; k <= 100; k++)
                    dist[j][k] = 1e18;
              ll tank, s, e;
            scanf("%lld %lld %lld", &tank, &s, &e);
              priority_queue <car> pq;
            pq.push( car(s, 0, 0) );
            dist[s][0] = 0;
            while(!pq.empty()) {
                car tmp = pq.top();
                pq.pop();
                  ll u = tmp.u;
                ll c = tmp.c;
                ll fil = tmp.fil;
                if(u == e) {
                    ans = min(ans, c);
                    break;
                }
                  if(dist[u][fil] != c)
                    continue;
                  for(ll j = 0; j < edge[u].size(); j++) {
                    ll nd = edge[u][j].v;
                    ll lagbe = edge[u][j].w;
                      for(ll k = max(lagbe, fil); k <= tank; k++) {
                        ll need = k - fil;
                          if(dist[nd][k - lagbe] > c + need * cost[u]) {
                            dist[nd][k - lagbe] = c + need * cost[u];
                            pq.push( car(nd, dist[nd][k - lagbe], k - lagbe) );
                        }
                    }
                }
              }
              if(ans != 1e18)
                printf("%lld\n", ans);
            else
                printf("impossible\n");
        }
      }
    return 0;
}
 
