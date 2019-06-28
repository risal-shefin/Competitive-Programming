#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int t, i, a, b, s;
    double l, w, ld, th, sm, cr;
    scanf("%d", &t);
    for(i = 1; i<= t; i++) {
        scanf("%d : %d", &a, &b);
        s = a + b;
        ld = sqrt(a * a + b * b) / 2.0;
        th = acos((2.0 * ld * ld - b * b) / (2.0 * ld * ld));
        sm = ld * th;
        cr = a + sm;
        l = (200.0 * a) / cr;
        w = (b * l) / (a * 1.0);
        printf("Case %d: %lf %lf\n", i, l, w);
    }
        return 0;
}
