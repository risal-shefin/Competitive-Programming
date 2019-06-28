#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> g[1005];
ll cst[1005], ts = 0;
bitset <1005> v;
ll dfs(ll u)
{
    if(v[u]) return 0;
    v[u] = 1;
    ts += cst[u];
      ll rt = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        rt += dfs(nd);
    }
      return rt;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        v.reset();
        ll n, e;
        scanf("%lld %lld", &n, &e);
          ll sum = 0;
        for(ll i = 1; i <= n; i++) {
            g[i].clear();
            scanf("%lld", &cst[i]);
            sum += cst[i];
        }
          for(ll i = 1; i <= e; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
          if(sum % n != 0) {
            printf("Case %lld: No\n", ++cs);
            continue;
        }
          ll eq = sum / n;
          bool chk = 1;
        for(ll i = 1; i <= n; i++) {
            if(v[i] == 0) {
                ts = 0;
                ll tot = dfs(i);
                if(ts % tot != 0) {
                    chk = 0;
                    break;
                }
                else if(ts / tot != eq) {
                    chk = 0;
                    break;
                }
            }
        }
          printf("Case %lld: ", ++cs);
        if(chk)
            printf("Yes\n");
        else
            printf("No\n");
    }
      return 0;
}
 
