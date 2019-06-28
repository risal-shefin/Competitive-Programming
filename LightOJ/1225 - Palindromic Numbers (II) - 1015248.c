#include <stdio.h>
int main()
{
    int T, n, i, rem, n2, num;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        num = 0;
        scanf("%d", &n);
        n2 = n;
        while(n2 > 0) {
            rem = n2 % 10;
            n2 = n2 / 10;
            num = num * 10 + rem;
        }
          if(num == n) {
            printf("Case %d: Yes\n", i);
        }
          else {
            printf("Case %d: No\n", i);
        }
    }
      return 0;
}
 
