#include <stdio.h>
int coin[100], num[100];
int ret[55][1010];
int ways(int n, int k)
   {
     if(ret[n][k] != -1)
          return ret[n][k];
    int ans = 0;
    for(int i = 0; i <= num[n] && i * coin[n] <= k; i++) {
        ans += ways(n - 1, k - i * coin[n]);
        ans %= 100000007;
    }
       ret[n][k] = ans;
     return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int j = 1; j <= n; j++)
            scanf("%d", &coin[j]);
        for(int j = 1; j <= n; j++)
            scanf("%d", &num[j]);
          for(int j = 1; j <= n; j++) {
            for(int l = 0; l <= k; l++) {
                ret[j][l] = -1;
            }
        }
          ret[0][0] = 1;
      for(int j = 1; j <= k; j++)
            ret[0][j] = 0;
          int ans = ways(n, k);
        printf("Case %d: %d\n", i,  ans);
    }
      return 0;
}
 
