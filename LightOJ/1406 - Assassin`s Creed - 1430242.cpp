#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1 << 15];
vector <ll> g[20];
bool vis[20][1 << 15], pos[1 << 15];
void dfs(ll u, ll msk)
{
    vis[u][msk] = 1;
    pos[msk] = 1;    /// covering this msk by one assassin is possible
    dp[msk] = 1;
      for(ll v: g[u]) {
        if(!vis[v][msk | (1 << v)])
            dfs(v, msk | (1 << v));
    }
}
ll solve(ll n)
{
    dp[0] = 0;
    // iterate over all the masks
    for(int mask = 0; mask < (1<<n); mask++) {
          // iterate over all the subsets of the mask
        for(int i = mask; i > 0; i = (i-1) & mask){
            if(!pos[i])
                continue;
              dp[mask] = min(dp[mask], 1 + dp[mask ^ i] );
        }
    }
      return dp[(1 << n) - 1];
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i < (1 << 15); i++)
            dp[i] = 1e15;
          memset(pos, 0, sizeof(pos));
        memset(vis, 0, sizeof(vis));
          ll n, m;
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= m; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            u--, v--;
              g[u].push_back(v);
        }
          for(ll i = 0; i < n; i++) {
              /// putting assassin on i city
            dfs(i, 1 << i);
        }
          printf("Case %lld: %lld\n", ++cs, solve(n) );
          for(ll i = 0; i <= n; i++)
            g[i].clear();
    }
      return 0;
}
   
