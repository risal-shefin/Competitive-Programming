#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("o22.txt", "w", stdout);
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll ax, ay, bx, by, cx, cy, dx, dy;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
          ll dx1 = bx - ax, dy1 = by - ay;
        ll dx2 = dx - cx, dy2 = dy - cy;
          ll cnt = 100;
        double lo = 0, hi = 1, ans = 1e18;
        while(cnt--) {
            double mid1 = (2 * lo + hi) / 3;
            double mid2 = (lo + 2 * hi) / 3;
              double x1 = ax + dx1 * mid1, y1 = ay + dy1 * mid1;
            double x2 = cx + dx2 * mid1, y2 = cy + dy2 * mid1;
            double dist1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            dist1 = sqrt(dist1);
              x1 = ax + dx1 * mid2, y1 = ay + dy1 * mid2;
            x2 = cx + dx2 * mid2, y2 = cy + dy2 * mid2;
            double dist2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            dist2 = sqrt(dist2);
              //cout << dist1 << "  " << dist2 << endl;
            if(dist1 <= dist2) {
                hi = mid2;
                ans = min(ans, dist1 );
            }
            else {
                lo = mid1;
                ans = min(ans, dist2 );
            }
        }
          printf("Case %lld: %0.9f\n", ++cs ,ans);
    }
      return 0;
}
 
