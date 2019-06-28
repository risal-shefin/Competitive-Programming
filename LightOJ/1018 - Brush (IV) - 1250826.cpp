#include <bits/stdc++.h>
using namespace std;
#define ll int
ll n, dp[1 << 16];
ll dist[17][17];
struct node {
    ll x, y;
} ara[20];
ll solve(ll mask)
{
    if(mask == (1 << n) - 1)
        return 0;
      ll &ret = dp[mask];
    if(ret != -1)
        return ret;
      ll rt = 1e9, tmp, slope, slope2;
    for(ll i = 0; i < n; i++) {
        if( ( (mask >> i) & 1 ) )
            continue;
          for(ll j = 0; j < n; j++) {
            if(j == i)
                continue;
            if( ( (mask >> j) & 1 ) )
                continue;
              ll msk = (1 << i) | dist[i][j];
            msk |= mask;
            tmp = solve(msk);
              rt = min(rt, tmp + 1);
        }
        if(rt == 1e9)
            rt = 1;
        break;
    }
      return ret = rt;
}
int main()
{
    //freopen("out.txt", "w", stdout);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
          scanf("%d", &n);
          for(ll i = 0; i < n; i++)
            scanf("%d %d", &ara[i].x, &ara[i].y);
          ll slope, slope2, mask;
        for(ll i = 0; i < n; i++) {
              for(ll j = 0; j < n; j++) {
                if(i == j)
                    continue;
                mask = (1 << j);
                for(ll k = 0; k < n; k++) {
                    if(i == k || j == k)
                        continue;
                      slope = (ara[j].y - ara[i].y) * (ara[k].x - ara[i].x);
                    slope2 = (ara[k].y - ara[i].y) * (ara[j].x - ara[i].x);
                      if(slope2 == slope) {
                        //cout << 5;
                        mask |= (1 << k);
                    }
                }
                //cout << mask << "  " << i << "  " << j << endl;
                dist[i][j] = mask;
            }
        }
          printf("Case %d: %d\n", ++caseno, solve(0));
    }
      return 0;
}
