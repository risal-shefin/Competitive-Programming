#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[2][2][35][2][40];
vector <ll> num;
ll solve(ll isStart, ll isSmall, ll pos, ll last, ll val)
{
    if(pos == 0)
        return val;
    ll &ret = dp[isStart][isSmall][pos][last][val];
    if(ret != -1 && isSmall)
        return ret;
      ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 1;
    else
        lim = num[pos2];
      ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i, val + (last == 1 && i == 1) );
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i, val + (last == 1 && i == 1) );
          rt += solve(1, 1, pos - 1, 0, 0);
    }
      return ret = rt;
}
ll calc(ll n)
{
    if(n <= 1)
        return 0;
      ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 2);
        tmp /= 2;
    }
    reverse(num.begin(), num.end());
      return solve(1, 0, num.size(), 0, 0);
}
int main()
{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll r;
        scanf("%lld", &r);
          ll ans = calc(r);
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
