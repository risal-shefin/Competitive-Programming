#include <bits/stdc++.h>
using namespace std;
int coin[105];
int ans[10005];
int main()
{
    int t;
    int n, k;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &k);
        for(int j = 1; j <= n; j++)
            scanf("%d", &coin[j]);
          for(int j = 1; j <= 10005; j++)
            ans[j] = 0;
        ans[0] = 1;
          for(int j = 1; j <= n; j++) {
            for(int l = 1; l <= k; l++) {
                if(coin[j] <= l) {
                    ans[l] += ans[l - coin[j]];
                    if(ans[l] >= 100000007)
                        ans[l] %= 100000007;
                }
            }
        }
          printf("Case %d: %d\n", i, ans[k]);
    }
      return 0;
}
 
