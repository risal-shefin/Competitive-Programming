#include <stdio.h>
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(!(n ^ 0)) {
            printf("%d %d\n", n, n);
        }
        else if(n > 10) {
            printf("10 %d\n", (n - 10));
        }
        else {
            printf("%d %d\n", 1, n - 1);
        }
    }
      return 0;
}
