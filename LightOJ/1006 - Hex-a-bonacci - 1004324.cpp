#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int n;
        long long int ara[10009];
        for(int j = 0; j < 6; j++) {
            scanf("%lld", &ara[j]);
        }
          scanf("%d", &n);
          for(int j = 6; j <= n; j++) {
            ara[j] = (ara[j - 1] + ara[j - 2] + ara[j - 3] + ara[j - 4] + ara[j - 5] + ara[j - 6]) % 10000007;
        }
          printf("Case %d: %lld\n", i, ara[n] % 10000007);
    }
      return 0;
}
 
