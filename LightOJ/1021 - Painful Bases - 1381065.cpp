#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k, len, dp[1 << 16][25], base;
char num[20];
ll solve(ll msk, ll rem, ll pos)
{
    if(pos == len)
        return rem == 0;
      ll &ret = dp[msk][rem];
    if(ret != -1)
        return ret;
      ret = 0;
    for(ll i = 0; i < len; i++) {
        ll n;
        if(isalpha(num[i]))
            n = num[i] - 'A' + 10;
        else
            n = num[i] - '0';
          if( (msk >> n) & 1)
            continue;
          ret += solve(msk | (1 << n), (n + rem * base) % k, pos + 1);
    }
      return ret;
}
int main()
{
//freopen("out.txt", "w", stdout);
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &base, &k);
        scanf("%s", num);
        len = strlen(num);
          ll ans = solve(0, 0, 0);
          printf("Case %lld: %lld\n", ++cs, ans);
    }
      return 0;
}
 
