#include <stdio.h>
int main()
{
    int T, j;
    long long int sum, n, m;
    scanf("%d", &T);
    for(j = 1; j <= T; j++) {
        scanf("%lld %lld", &n, &m);
        sum = (n * m) / 2;
          printf("Case %d: %lld\n", j, sum);
    }
      return 0;
}
