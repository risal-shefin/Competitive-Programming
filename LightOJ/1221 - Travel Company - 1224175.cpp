#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node {
    ll u, v, i, e;
    node(ll _u, ll _v, ll _i, ll _e) {
        u = _u;
        v = _v;
        i = _i;
        e = _e;
    }
};
ll dist[110], ex[110], in[110];
vector <node> graph;
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 105; i++) {
            dist[i] = 1e18;
            ex[i] = 0;
            in[i] = 0;
        }
          ll n, r, p;
        scanf("%lld %lld %lld", &n, &r, &p);
          for(ll i = 1; i <= r; i++) {
            ll u, v, ii, e;
            scanf("%lld %lld %lld %lld", &u, &v, &ii, &e);
            graph.pb( node(u, v, ii, e) );
        }
          dist[0] = 0, ex[0] = 0, in[0] = 0;
        for(ll i = 1; i < n; i++) {
            for(ll j = 0; j < graph.size(); j++) {
                node e = graph[j];
                  ll tote = e.e + ex[e.u], toti = e.i + in[e.u];
                ll cst = tote * p - toti;
                  if(dist[e.v] > cst) {
                    dist[e.v] = cst;
                    ex[e.v] = tote;
                    in[e.v] = toti;
                }
            }
        }
          bool test = 0;
        for(ll j = 0; j < graph.size(); j++)
        {
            node e = graph[j];
              ll tote = e.e + ex[e.u], toti = e.i + in[e.u];
            ll cst = tote * p - toti;
              if(dist[e.v] > cst)
            {
                test = 1;
                break;
            }
        }
          printf("Case %lld: ", ++caseno);
        if(test)
            printf("YES\n");
        else
            printf("NO\n");
          graph.clear();
    }
      return 0;
}
 
