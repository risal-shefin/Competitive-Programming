#include <stdio.h>
int main()

{
    int d1, d2, d3, d;
    scanf("%d %d %d", &d1, &d2, &d3);
    if((d1 + d3) < d2) {
        d = d1 + d3 + d3 + d1;
        printf("%d\n", d);
        return 0;
    }

    else if((d2 + d3) < d1) {
        d = d2 + d3 + d3 +d2;
        printf("%d\n", d);
        return 0;
    }

        d = d1;
        if((d + d2 + d2) < (d3 + d2)) {
            d += d + d2 + d2;
        }
        else {
            d += d3 + d2;
        }
    printf("%d\n", d);
    return 0;
}