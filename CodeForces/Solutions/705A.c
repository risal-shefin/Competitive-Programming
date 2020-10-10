#include <stdio.h>

int main()

{
    int n, i;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        if(i > 1) {
            printf(" that ");
        }

        if(i & 1) {
            printf("I hate");
        }
        else {
            printf("I love");
        }
    }

    printf(" it\n");
    return 0;
}