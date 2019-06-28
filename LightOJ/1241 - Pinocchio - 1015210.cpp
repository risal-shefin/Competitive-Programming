#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &n);
        int ara[n], count = 0, cnt;
        for(int j = 1; j <= n; j++) {
            scanf("%d", &ara[j - 1]);
            if(j != 1) {
                if(ara[j - 1] > ara[j - 2]) {
                    cnt = ara[j - 1] - ara[j - 2];
                    count += ceil(cnt / 5.0);
                }
            }
              else {
                cnt = ara[0] - 2;
                count = ceil(cnt / 5.0);
            }
        }
          printf("Case %d: %d\n", i, count);
    }
      return 0;
}
