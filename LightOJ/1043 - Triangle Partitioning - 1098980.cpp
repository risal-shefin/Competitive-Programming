#include <bits/stdc++.h>
using namespace std;
#define eps 1e-12
int main()
{
    int T;
    scanf("%d", &T);
    int caseno = 0;
    while(T--) {
        double AB, AC, BC, DE, AD, AE, AF, AG, r;
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);
        double B = acos( (AB * AB + BC * BC - AC * AC) / (2.0 * AB * BC) );
        double C = acos( (BC * BC + AC * AC - AB * AB) / (2.0 * BC * AC) );
        AG = AC * sin(C);
        double ABC = 0.5 * BC * AG;
          double lo = 0.000000000001, hi = AB, counter = 100;
        while(counter--) {
            double mid = (lo + hi) / 2.0;
            AE = (mid * AC) / AB;
            DE = (mid * BC) / AB;
            AF = sin(C) * AE;
            double ADE = 0.5 * DE * AF;
            double BDEC = ABC - ADE;
            double r2 = ADE / BDEC;
              if(r2 > 0 && abs(r2 - r) <= eps) {
                AD = mid;
            }
              if(r2 > r)
                hi = mid;
            if(r2 < r)
                lo = mid;
          }
          printf("Case %d: %0.10f\n", ++caseno, AD);
    }
}
 
