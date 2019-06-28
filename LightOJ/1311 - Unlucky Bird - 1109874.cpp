#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        double u1, u2, v3, a1, a2;
        scanf("%lf %lf %lf %lf %lf", &u1, &u2, &v3, &a1, &a2);
          double t1 = u1 / a1;
        double t2 = u2 / a2;
        double t = max(t1, t2);
        double distb = v3 * t;
        double s1 = (u1 * u1) / (2.0 * a1);
        double s2 = (u2 * u2) / (2.0 * a2);
          printf("Case %d: %0.8f %0.8f\n", ++caseno, s1 + s2, distb);
    }
      return 0;
}
 
