#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int j = 1; j <= T; j++) {
        int n;
        scanf("%d", &n);
        int x1[n], x2[n], y1[n], y2[n], z1[n], z2[n];
        for(int i = 0; i < n; i++)
            scanf("%d %d %d %d %d %d", &x1[i], &y1[i], &z1[i], &x2[i], &y2[i], &z2[i]);
          int xl = INT_MIN, xh  = INT_MAX, yl = INT_MIN, yh = INT_MAX, zl = INT_MIN, zh = INT_MAX;
          for(int i = 0; i < n; i++) {
            xl = max(xl, x1[i]);
            xh = min(xh, x2[i]);
            yl = max(yl, y1[i]);
            yh = min(yh, y2[i]);
            zl = max(zl, z1[i]);
            zh = min(zh, z2[i]);
        }
          int vol = (xh - xl) * (yh - yl) * (zh - zl);
          printf("Case %d: %d\n", j, vol > 0 ? vol : 0);
    }
      return 0;
}
 
