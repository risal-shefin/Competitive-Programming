#include <stdio.h>
#include <math.h>
int main()
{
    int T, i, Ox, Oy, Ax, Ay, Bx, By;
    double a, c, pi, th, arc;
    pi = 2.0 * acos(0.00);
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d %d %d %d %d", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
        a = (Ox - Bx) * (Ox - Bx) + (Oy - By) * (Oy - By);
        a = sqrt(a);
        c = (Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By);
        c = sqrt(c);
        th = (a * a + a * a - c * c) / (2.0 * a * a);
        th = acos(th);
        arc = th * a;
          printf("Case %d: %lf\n",i, arc);
    }
      return 0;
}
