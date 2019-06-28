#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> g[50009];
ll ara[50009], par[50009], ans[50009];
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 50000; i++) {
            g[i].clear();
            par[i] = 0;
        }
          ll n;
        scanf("%lld", &n);
          for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          for(ll i = 2; i <= n; i++) {
            g[ ara[i - 1] ].push_back(ara[i]);
            g[ ara[i] ].push_back(ara[i - 1]);
        }
          for(ll i = 1; i <= 50000; i++)
            sort(g[i].begin(), g[i].end());
          ll s = ara[1], e = ara[n];
        queue <ll> q;
        q.push(s);
        par[s] = -1;
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
              for(ll i = 0; i < g[u].size(); i++) {
                ll nd = g[u][i];
                  if(par[nd] == 0) {
                    par[nd] = u;
                    q.push(nd);
                      if(nd == e) {
                        while(!q.empty()) q.pop();
                        break;
                    }
                }
            }
          }
          ll indx = 0, node = e;
        while(node != -1) {
            ans[indx++] = node;
            node = par[node];
        }
          printf("Case %lld:\n", ++cs);
        for(ll i = indx - 1; i >= 0; i--) {
            if(i != indx - 1)
                printf(" ");
            printf("%lld", ans[i]);
        }
        printf("\n");
      }
      return 0;
}
 
