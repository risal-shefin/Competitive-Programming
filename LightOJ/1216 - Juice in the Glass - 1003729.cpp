#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double r1, r2, h, p, vol;
        double x, r3;
        cin >> r1 >> r2 >> h >> p;
        x = (h * r2) / (r1 - r2);
        r3 = ((p + x) * r2) / x;
        vol = (1.0 / 3.0) * pi * r3 * r3 * (p + x) - ((1.0 / 3.0) * pi * r2 * r2 * x);
        printf("Case %d: %0.9lf\n", i, vol);
    }
      return 0;
}
 
