#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, w, k;
ll dp[105][105];
struct node {
    ll x, y;
} ara[105];
bool cmp(node a, node b)
{
    return a.y < b.y;
}
ll solve(ll indx, ll mv)
{
    if(mv == k)
        return 0;
    if(indx >= n)
        return 0;
    ll &ret = dp[indx][mv];
      if(ret != -1)
        return ret;
      ll rt = solve(indx + 1, mv);
      ll lo = indx, hi = n - 1, ans;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
          if(ara[mid].y - ara[indx].y <= w) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
      rt = max(rt, solve(ans + 1, mv + 1) + ans - indx + 1);
      return ret = rt;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld %lld", &n, &w, &k);
        for(ll i = 0; i < n; i++)
            scanf("%lld %lld", &ara[i].x, &ara[i].y);
          sort(ara, ara + n, cmp);
          printf("Case %lld: %lld\n", ++caseno, solve(0, 0) );
    }
    return 0;
}
 
