#include <stdio.h>
#include <math.h>
int main()
{
    int T, i;
    double r1, r2, r3, a, b, c, s;
    double circar, triar;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
    scanf("%lf %lf %lf", &r1, &r2, &r3);
    a = r1 + r2;
    b = r2 + r3;
    c = r1 + r3;
    s = (a + b + c) / 2.0;
    triar = sqrt(s * (s - a) * (s - b) * (s - c));
    circar = (r1 * r1) / 2.0 * acos((c * c + a * a - b * b) / (2.0 * c * a)) + (r3 * r3) / 2.0 * acos((b * b + c * c - a * a) / (2.0 * b * c)) + (r2 * r2) / 2.0 * acos((a * a + b * b - c * c) / (2.0 * a * b));
    printf("Case %d: %lf\n", i, triar - circar);
    }
        return 0;
}
