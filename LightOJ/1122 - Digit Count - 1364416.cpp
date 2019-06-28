#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[12][12], m, n, dig[10];
ll solve(ll pos, ll last)
{
    if(pos == 0)
        return 1;
    ll &ret = dp[pos][last];
    if(ret != -1)
        return ret;
      ll pos2 = n - pos;
      ll rt = 0;
    for(ll i = 1; i <= m; i++) {
        if(last == 0 || abs(dig[i] - last) <= 2)
            rt += solve(pos - 1, dig[i]);
    }
      return ret = rt;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &m, &n);
        for(ll i = 1; i <= m; i++)
            scanf("%lld", &dig[i]);
          printf("Case %lld: %lld\n", ++caseno, solve(n, 0) );
    }
      return 0;
}
