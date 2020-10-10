#include <stdio.h>

int main()

{
    int n, p, v, t, i, count = 0;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%d %d %d", &p, &v, &t);
        if((p == 1 && v == 1) || (p == 1 && t == 1) || (v == 1 && t == 1)) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}