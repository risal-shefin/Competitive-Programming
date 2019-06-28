#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[2][2][12][90][90];
vector <ll> num;
ll k;
ll solve(ll isStart, ll isSmall, ll pos, ll rem, ll sumd)
{
    if(pos == 0) {
        if(rem == 0 && sumd % k == 0)
            return 1;
        else
            return 0;
    }
      ll &ret = dp[isStart][isSmall][pos][rem][sumd];
    if(ret != -1 && isSmall)
        return ret;
      ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];
      ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (rem * 10 + i) % k, sumd + i);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (rem * 10 + i) % k, sumd + i);
          rt += solve(1, 1, pos - 1, 0, 0);
    }
      return ret = rt;
}
ll calc(ll n)
{
    if(n <= 0)
        return 0;
      ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());
      return solve(1, 0, num.size(), 0, 0) - 1;
}
int main()
{
    //freopen("out.txt", "w", stdout);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        ll l, r;
        scanf("%lld %lld %lld", &l, &r, &k);
          if(k > 82) {
            printf("Case %lld: 0\n", ++caseno);
            continue;
        }
          ll ans = calc(r);
          ans -= calc(l - 1);
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
