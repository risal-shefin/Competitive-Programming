#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll rad[509][509], ur[509][509], cr[509][509], cu[509][509], dp[509][509], m, n;
ll solve(ll x, ll y)
{
    if(x <= 0 || y <= 0 || x > m || y > n)
        return 0;
    ll &ret = dp[x][y];
    if(ret != -1)
        return ret;
      return ret = max(cu[x][y] + solve(x - 1, y), cr[x][y] + solve(x, y - 1));
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &m, &n);
          for(ll i = 1; i <= m; i++) {
            for(ll j = 1; j <= n; j++) {
                scanf("%lld", &ur[i][j]);
            }
        }
          for(ll i = 1; i <= m; i++) {
            for(ll j = 1; j <= n; j++) {
                scanf("%lld", &rad[i][j]);
            }
        }
          for(ll i = 1; i <= m; i++) {
            for(ll j = 1; j <= n; j++) {
                cu[i][j] = ur[i][j] + cu[i][j - 1];
            }
        }
          for(ll j = 1; j <= n; j++) {
            for(ll i = 1; i <= m; i++) {
                cr[i][j] = rad[i][j] + cr[i - 1][j];
            }
        }
          printf("Case %lld: %lld\n", ++caseno, solve(m, n));
      }
      return 0;
}
 
