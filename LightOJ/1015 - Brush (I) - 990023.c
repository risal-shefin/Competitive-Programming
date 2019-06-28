#include <stdio.h>
int main()
{
    int T, i, N, j, sum;
    int ara[1020];
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d", &N);
          sum = 0;
        for(j = 0; j < N; j++) {
            scanf("%d", &ara[j]);
            if(ara[j] > 0)
                sum += ara[j];
        }
            printf("Case %d: %d\n", i, sum);
    }
      return 0;
}
 
