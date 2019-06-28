#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dist[10009][13];
struct graph {
    ll v;
    ll w;
    graph(ll _v, ll _w) {
        v = _v;
        w = _w;
    }
};
vector <graph> edge[10009], wedge[10009];
struct node {
    ll u;
    ll c;
    ll cnt;
    node(ll _u, ll _c, ll _cnt) {
        u = _u;
        c = _c;
        cnt = _cnt;
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
          for(ll i = 0; i <= 10000; i++) {
            for(ll j = 0; j <= 11; j++)
                dist[i][j] = 1e18;
              edge[i].clear();
            wedge[i].clear();
        }
          ll n, m, k, d;
        scanf("%lld %lld %lld %lld", &n, &m, &k, &d);
          for(ll i = 1; i <= m; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            edge[u].push_back( graph(v, w) );
        }
        //cout << "  kwuefhkwf " << edge[0].size() << endl;
          for(ll i = 1; i <= k; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            wedge[u].push_back( graph(v, w) );
        }
          priority_queue <node> pq;
        pq.push( node(0, 0, 0));
        dist[0][0] = 0;
          while(!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
              ll u = tmp.u;
            ll c = tmp.c;
            ll cnt = tmp.cnt;
              if(dist[u][cnt] != c)
                continue;
           if(u == n - 1) {
               dist[n-1][cnt] = c;
               break;
           }
              //cout << edge[0].size() << endl;
            for(ll i = 0; i < edge[u].size(); i++) {
                ll nd = edge[u][i].v;
                ll cst = edge[u][i].w;
                  //cout << nd << endl;
                if(dist[nd][cnt] > c + cst) {
                    dist[nd][cnt] = c + cst;
                    pq.push( node(nd, dist[nd][cnt], cnt) );
                }
            }
              for(ll i = 0; i < wedge[u].size(); i++) {
                ll nd = wedge[u][i].v;
                ll cst = wedge[u][i].w;
                  if(dist[nd][cnt + 1] > c + cst && cnt < d) {
                    dist[nd][cnt + 1] = c + cst;
                    pq.push( node(nd, dist[nd][cnt + 1], cnt + 1) );
                }
            }
          }
          ll ans = 1e18;
        for(ll i = 0; i <= 10; i++)
            ans = min(ans, dist[n - 1][i]);
          printf("Case %lld: ", ++caseno);
        if(ans == 1e18)
            printf("Impossible\n");
        else
            printf("%lld\n", ans);
    }
      return 0;
}
