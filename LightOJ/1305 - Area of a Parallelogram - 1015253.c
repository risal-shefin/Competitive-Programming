#include <stdio.h>
#include <math.h>
int main()
{
    int T, i;
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    double AB, BC, AC, area, s;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        Dx = Ax + Cx - Bx;
        Dy = Ay + Cy - By;
          AB = sqrt(((Ax - Bx) * (Ax - Bx)) + ((Ay - By) * (Ay - By)));
        BC = sqrt(((Bx - Cx) * (Bx - Cx)) + ((By - Cy) * (By - Cy)));
        AC = sqrt(((Ax - Cx) * (Ax - Cx)) + ((Ay - Cy) * (Ay - Cy)));
        s = (AB + BC + AC) / 2.0;
        area = sqrt(s * (s- AB) * (s - BC) * (s - AC));
        area *= 2.0;
          printf("Case %d: %0.0lf %0.0lf %0.0lf\n", i, Dx, Dy, area);
    }
      return 0;
}
