#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[102][102], ara[102];
ll solve(ll start, ll stop)
{
    if(start > stop)
        return 0;
      ll &ret = dp[start][stop];
    if(ret != -1)
        return ret;
      ll sum = 0, rt, mx = -1e18;
    for(ll i = start; i <= stop; i++) {
        rt = solve(i + 1, stop);
        sum += ara[i];
        mx = max(mx, sum - rt);
    }
      sum = 0;
    for(ll i = stop; i >= start; i--) {
        rt = solve(start, i - 1);
        sum += ara[i];
        mx = max(mx, sum - rt);
    }
      return ret = mx;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          printf("Case %lld: %lld\n", ++cs, solve(1, n));
    }
    return 0;
}
 
