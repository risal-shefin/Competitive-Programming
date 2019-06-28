#include <stdio.h>
int main()
{
    int T, i;
    long long W, j, k;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%lld", &W);
        if(W & 1)
            printf("Case %d: Impossible\n", i);
        else {
            for(j = W / 2; j >= 3; j /= 2) {
                if(W % j == 0 && j % 2 != 0) {
                    k = W / j;
                    break;
                }
            }
              printf("Case %d: %lld %lld\n", i, j, k);
        }
      }
    return 0;
}
 
