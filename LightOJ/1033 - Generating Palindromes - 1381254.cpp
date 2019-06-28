#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[110][110];
string s;
ll solve(ll left, ll right)
{
    if(left >= right)
        return 0;
    ll &ret = dp[left][right];
    if(ret != -1)
        return ret;
      if(s[left] != s[right])
        ret = min(1 + solve(left + 1, right), 1 + solve(left, right - 1));
    else
        ret = solve(left + 1, right - 1);
      return ret;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
          ll right = s.length() - 1;
        ll ans = solve(0, right);
          printf("Case %lld: %lld\n", ++cs, ans);
    }
      return 0;
}
 
