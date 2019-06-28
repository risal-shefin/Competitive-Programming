#include <bits/stdc++.h>
using namespace std;
double L2, l;
#define pi acos(-1.0)
#define prc 1e-15
double bsearch(double lo, double hi)
{
    while(lo <= hi) {
        double mid = (lo + hi) / 2;
        double r = l / mid;
        double d = r * sin(mid / 2);
          if(abs(d - L2) <= prc) {
            return r - r * cos(mid / 2);
        }
        else if(d > L2)
            lo = mid;
        else
            hi = mid;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        double L, n, C, h;
        scanf("%lf %lf %lf", &L, &n, &C);
        l = (1.0 + n*C)*L;
        L2 = L / 2;
        if(n == 0) {
            printf("Case %d: 0\n", i);
        }
        else {
            h = bsearch(0, 2.0 * pi);
            printf("Case %d: %f\n", i, h);
        }
    }
      return 0;
}
 
