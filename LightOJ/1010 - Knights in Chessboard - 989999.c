#include  <stdio.h>
#include <math.h>
int main()
{
    int T, i, m, n, r, temp;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d", &m, &n);
        if(m == 1 || n == 1) {
            if(m == 1)
                r = n;
            else if(n == 1)
                r = m;
        }
          else if(m == 2 || n == 2) {
            if(m == 2) {
                if(n % 4 == 1)
                    r = n + 1;
                else if(n % 4 == 2)
                    r = n + 2;
                else if(n % 4 == 3)
                    r = n + 1;
                else if(n % 4 == 0)
                    r = n;
            }
            else if(n == 2) {
                if(m % 4 == 1)
                    r = m + 1;
                else if(m % 4 == 2)
                    r = m + 2;
                else if(m % 4 == 3)
                    r = m + 1;
                else if(m % 4 == 0)
                    r = m;
            }
        }
          else
            r = ceil((m * n) / 2.0);
          printf("Case %d: %d\n", i, r);
    }
      return 0;
}
 
