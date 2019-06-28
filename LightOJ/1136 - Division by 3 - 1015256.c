#include <stdio.h>
int main()
{
    int T, i;
    long long int A, B, count, count1, count2;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%lld %lld", &A, &B);
        if((A % 3) == 0) {
            count1 = 2 * (A / 3);
        }
        else if(((A + 1) % 3) == 0) {
            count1 = 2 * ((A + 1) / 3) - 1;
        }
        else if(((A - 1) % 3) == 0) {
            count1 = 2 * ((A - 1) / 3);
        }
          if((B % 3) == 0) {
            count2 = 2 * (B / 3);
        }
        else if(((B + 1) % 3) == 0) {
            count2 = 2 * ((B + 1) / 3) - 1;
        }
        else if(((B - 1) % 3) == 0) {
            count2 = 2 * ((B - 1) / 3);
        }
          if(((A - 1) % 3)) {
            count = count2 - count1 + 1;
        }
          else {
            count = count2 - count1;
        }
          printf("Case %d: %lld\n", i, count);
    }
      return 0;
}
