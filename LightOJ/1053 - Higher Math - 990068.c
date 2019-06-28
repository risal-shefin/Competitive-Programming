#include <stdio.h>
int main()
{
    int T, a, b, c, n1, n2, mx, i;
      scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d %d", &a, &b, &c);
        mx = a;
        n1 = b;
        n2 = c;
        if(mx < b) {
            mx = b;
            n1 = a;
            n2 = c;
        }
        if(mx < c) {
            mx = c;
            n1 = a;
            n2 = b;
        }
          if(n1 * n1 + n2 * n2 == mx * mx)
            printf("Case %d: yes\n", i);
        else
            printf("Case %d: no\n", i);
    }
      return 0;
}
 
