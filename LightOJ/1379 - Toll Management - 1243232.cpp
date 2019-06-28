#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll v;
    ll c;
    node(ll _v, ll _c) {
        v = _v;
        c = _c;
    }
};
bool operator <(node a, node b)
{
    return a.c > b.c;
}
ll s, t, ans, p, dist1[10009], dist2[10009];
vector <node> graph[10009], revgraph[10009];
int main()
{
    ll test, caseno = 0;
    cin >> test;
    while(test--) {
          for(ll i = 0; i <= 10009; i++) {
            graph[i].clear();
            revgraph[i].clear();
            dist1[i] = 1e9;
            dist2[i] = 1e9;
        }
          ll n, m;
        scanf("%lld %lld %lld %lld %lld", &n, &m, &s, &t, &p);
        for(ll i = 1; i <= m; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            graph[u].push_back( node(v, c) );
            revgraph[v].push_back( node(u, c) );
        }
          priority_queue <node> pq;
        pq.push( node(s, 0) );
        dist1[s] = 0;
          while(!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
              ll u = tmp.v;
            ll c = tmp.c;
              if(dist1[u] != c)
                continue;
              for(ll i = 0; i < graph[u].size(); i++) {
                ll nd = graph[u][i].v;
                ll cst = graph[u][i].c;
                  if(dist1[nd] > c + cst) {
                    dist1[nd] = c + cst;
                    pq.push( node(nd, dist1[nd]) );
                }
            }
          }
          pq.push( node(t, 0) );
        dist2[t] = 0;
          while(!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
              ll u = tmp.v;
            ll c = tmp.c;
              if(dist2[u] != c)
                continue;
              for(ll i = 0; i < revgraph[u].size(); i++) {
                ll nd = revgraph[u][i].v;
                ll cst = revgraph[u][i].c;
                  if(dist2[nd] > c + cst) {
                    dist2[nd] = c + cst;
                    pq.push( node(nd, dist2[nd]) );
                }
            }
          }
          ans = -1;
        for(ll i = 1; i <= n; i++) {
            for(ll j = 0; j < graph[i].size(); j++) {
                ll nd = graph[i][j].v;
                ll cst = graph[i][j].c;
                  if(dist1[i] + dist2[nd] + cst <= p) {
                    ans = max(ans, cst);
                }
                              }
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
