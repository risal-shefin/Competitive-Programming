#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[12];
ll dp[1 << 10][1001], lim, len, d;
ll solve(ll msk, ll dv)
{
    if(msk == lim)
        return dv == 0;
    ll &ret = dp[msk][dv];
    if(ret != -1)
        return ret;
      ret = 0;
    ll mark = 0;
    for(ll i = 0; i < len; i++) {
        if((msk >> i) & 1)
            continue;
        if((mark >> (s[i] - '0')) & 1)
            continue;
          ret += solve(msk | (1 << i), (dv * 10 + (s[i] - '0') ) % d);
          mark |= (1 << (s[i] - '0'));
    }
      return ret;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
          scanf("%s %lld", s, &d);
        len = strlen(s), lim = (1 << len) - 1;
          ll n = 0;
        for(ll i = 0; i < len; i++)
            n = n * 10 + (s[i] - '0');
          printf("Case %lld: %lld\n", ++caseno, n == 0? 1LL: solve(0, 0));
    }
      return 0;
}
 
