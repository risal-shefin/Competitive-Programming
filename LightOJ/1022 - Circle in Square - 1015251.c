#include <stdio.h>
#include <math.h>
int main()
{
    int i, T;
    double r, ans, pi;
      scanf("%d", &T);
    pi = 2.0 * acos(0.0);
    for(i = 1; i <= T; i++) {
        scanf("%lf", &r);
        ans = ((4.0 * r * r) - (pi * r * r)) + 0.000001;
        printf("Case %d: %0.2lf\n",i, ans);
    }
    return 0;
}
