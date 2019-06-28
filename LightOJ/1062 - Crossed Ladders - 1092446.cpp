#include  <bits/stdc++.h>
using namespace std;
#define er 1e-12
int main()
{
    double x, y, c;
    int i, n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf %lf %lf", &x, &y, &c);
          int tmp = 100;
        double lo = 0, hi = min(x, y), w;
        while(tmp--) {
            double mid = (lo + hi) / 2;
            double h1 = sqrt(x * x - mid * mid);
            double h2 = sqrt(y * y - mid * mid);
            double ct = (h1 * h2) / (h1 + h2);
              if(abs(ct - c) <= er) {
                w = mid;
            }
              if(ct > c)
                lo = mid;
            else
                hi = mid;
        }
          printf("Case %d: %f\n", i, w);
    }
      return 0;
}
 
