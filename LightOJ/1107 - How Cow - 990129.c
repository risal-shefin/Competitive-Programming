#include <stdio.h>
int main()
{
    int T, i, j, M, x1, y1, x2, y2, x3, y3;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &M);
        printf("Case %d:\n", i);
        for(j = 1; j <= M; j++) {
            scanf("%d %d", &x3, &y3);
            if(x3 > x1 && x3 < x2 && y3 > y1 && y3 < y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
      return 0;
}
 
