#include <stdio.h>

int main()

{
    int n, h, i, row = 0;
    scanf("%d %d", &n, &h);

    int ara[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        if(ara[i] > h) row += 2;
        else row++;
    }

    printf("%d\n", row);

    return 0;
}