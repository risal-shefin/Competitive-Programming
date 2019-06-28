#include <bits/stdc++.h>
using namespace std;
int n;
int ara[20][20];
int dp[18][1 << 18];
int marriage(int i, int btmask)
{
    if(dp[i][btmask] != -1)
        return dp[i][btmask];
    if(i == n)
        return 0;
      int sum = INT_MIN;
    for(int j = 0; j < n; j++) {
        if( (btmask & (1 << j) ) == 0) {
            sum = max(sum, marriage(i + 1, (1 << j) | btmask) + ara[i][j] );
        }
    }
      return dp[i][btmask] = sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    int caseno = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &ara[i][j]);
            }
        }
          memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", ++caseno, marriage(0, 0) );
    }
      return 0;
}
 
