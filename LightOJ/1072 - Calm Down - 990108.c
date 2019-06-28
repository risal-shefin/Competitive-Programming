#include <stdio.h>
#include <math.h>
#define pi acos(-1.)
int main()
{
    int T, i;
    double r, R, n, s;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%lf %lf", &R, &n);
        s = sin(pi / n);
        r = (R * s) / (1 + s);
        if(r - (int)r > 0)
            printf("Case %d: %0.10lf\n", i, r);
        else
            printf("Case %d: %0.0lf\n", i, r);
    }
      return 0;
}
 
