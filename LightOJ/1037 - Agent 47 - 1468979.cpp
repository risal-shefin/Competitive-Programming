#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1 << 15], h[20], dam[20][20], lim, shot[1 << 15][20], gun[20], n;
ll solve(ll msk)
{
    if(msk == lim - 1)
        return 0;
      ll &ret = dp[msk];
    if(ret != -1)
        return ret;
      ret = 1e18;
    for(ll i = 0; i < n; i++) {
        ll bt = (msk >> i) & 1;
        if(bt == 1)
            continue;
          ll lagbe = h[i] / shot[msk][i];
        if(lagbe * shot[msk][i] < h[i])
            lagbe++;
          ret = min(ret, lagbe + solve(msk | (1 << i)) );
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
          for(ll i = 0; i < n; i++)
            scanf("%lld", &h[i]);
          for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                char ch;
                scanf(" %c", &ch);
                dam[i][j] = (ch - '0');
            }
        }
          lim = 1 << n;
          for(ll i = 0; i < lim; i++) {
            ll indx = 0, bt;
            for(ll j = 0; j < n; j++) {
                bt = (i >> j) & 1;
                if(bt == 1)
                    gun[indx++] = j;
            }
              for(ll j = 0; j < n; j++) {
                shot[i][j] = 1;
                for(ll k = 0; k < indx; k++) {
                    if(gun[k] != j)
                        shot[i][j] = max(shot[i][j], dam[ gun[k] ][j]);
                }
            }
        }
          printf("Case %lld: %lld\n", ++cs, solve(0));
      }
      return 0;
}
 
