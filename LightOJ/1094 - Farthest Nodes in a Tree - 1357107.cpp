#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair <ll, ll>
#define vv first
#define cc second
vector <pii> g[30009];
ll dnd = 0, mx = -1;
void dfs(ll u, ll p, ll c)
{
    if(c > mx) {
        mx = c;
        dnd = u;
    }
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i].vv;
        ll cst = g[u][i].cc;
          if(nd != p)
            dfs(nd, u, c + cst);
    }
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i < n; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            g[u].pb( pii(v, c) );
            g[v].pb( pii(u, c) );
        }
          mx = -1;
        dfs(0, -1, 0);
        mx = -1;
        dfs(dnd, -1, 0);
          printf("Case %lld: %lld\n", ++cs, mx);
          for(ll i = 0; i < 30006; i++)
            g[i].clear();
    }
      return 0;
}
 
