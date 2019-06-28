#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[23][3], cst[23][3], n;
ll solve(ll pos, ll prv)
{
    if(pos <= 0)
        return 0;
    ll &ret = dp[pos][prv];
    if(ret != -1)
        return ret;
      ret = 1e18;
    for(ll i = 0; i < 3; i++) {
        if(i != prv || n == pos)
            ret = min(ret, cst[pos][i] + solve(pos - 1, i));
    }
      return ret;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
          scanf("%lld", &n);
          for(ll i = 1; i <= n; i++) {
            for(ll j = 0; j < 3; j++)
                scanf("%lld", &cst[i][j]);
        }
          printf("Case %lld: %lld\n", ++cs, solve(n, 0));
    }
    return 0;
}
 
