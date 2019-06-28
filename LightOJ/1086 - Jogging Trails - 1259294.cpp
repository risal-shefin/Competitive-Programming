#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dist[20][20], deg[20], ans = 0, sum = 0;
ll dp[1 << 15], n, m, mask = 0;
ll solve(ll mask)
{
    if(mask == 0)
        return 0;
    ll &ret = dp[mask];
    if(ret != -1)
        return ret;
      ll rt = 1e18, pos;
    for(ll i = 0; i < n; i++)
        if( (mask >> i) & 1) {
            pos = i + 1;
            break;
        }
      for(ll i = pos + 1; i <= n; i++) {
        if( (mask >> i) & 1 == 0)
            continue;
        rt = min(rt, solve( mask ^ (1 << (pos - 1)) ^ (1 << (i - 1)) ) + dist[pos][i]);
    }
      return ret = rt;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ans = 0, sum = 0, mask = 0;
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &n, &m);
          for(ll i = 0; i <= 15; i++) {
            deg[i] = 0;
            for(ll j = 0; j <= 15; j++)
                dist[i][j] = 1e18;
        }
          ll indx = 0;
        for(ll i = 1; i <= m; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
              dist[u][v] = dist[v][u] = min(dist[u][v], c);
            sum += c;
            deg[u]++;
            deg[v]++;
        }
          for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++)
                for(ll k = 1; k <= n; k++)
                    if(dist[i][k] > dist[i][j] + dist[j][k])
                        dist[i][k] = dist[i][j] + dist[j][k];
          //cout << ans << endl;
        for(ll i = 1; i <= n; i++)
            if(deg[i] % 2)
                mask |= (1 << (i - 1));
          ans += solve(mask) + sum;
        printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
