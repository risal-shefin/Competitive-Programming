#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll comp[2 * 105], cand[105];
ll prefcan[105][105], cost[2 * 105][105];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(comp, 0, sizeof(comp));
        ll n;
        scanf("%lld", &n);
          queue <ll> q;
        for(ll i = 1; i <= n; i++) {
            q.push(i);
            for(ll j = 1; j <= n; j++)
                scanf("%lld", &prefcan[i][j] );
        }
          for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                ll cnd;
                scanf("%lld", &cnd);
                cost[n + i][cnd] = j;
            }
        }
          while(!q.empty()) {
            ll mn = q.front();
            q.pop();
              for(ll i = 1; i <= n; i++) {
                ll wm = prefcan[mn][i];
                if(comp[wm] == 0) {
                    comp[wm] = mn;
                    cand[mn] = wm;
                    break;
                }
                else if(cost[wm][ comp[wm] ] > cost[wm][mn]) {
                    q.push(comp[wm]);
                    comp[wm] = mn;
                    cand[mn] = wm;
                    break;
                }
            }
        }
          printf("Case %lld:", ++caseno);
        for(ll i = 1; i <= n; i++) {
            printf(" (%lld %lld)", i, cand[i]);
        }
        printf("\n");
    }
      return 0;
}
   
