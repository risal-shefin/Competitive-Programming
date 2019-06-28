#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        string m1, m2;
        int d1, d2, y1, y2, lp, check = 0;
        cin >> m1;
        scanf("%d, %d", &d1, &y1);
        cin >> m2;
        scanf("%d, %d", &d2, &y2);
        y1--;
        lp = (y2 / 4 - y2 / 100 + y2 / 400) - (y1 / 4 - y1 / 100 + y1/ 400);
          y1++;
        if(y1 % 4 == 0 && (y1 % 100 != 0 || y1 % 400 == 0))
            check = 1;
        if(m1 != "January" && m1 != "February" && check == 1)
            lp--;
          if(y2 % 4 == 0 && (y2 % 100 != 0 || y2 % 400 == 0))
            check = 2;
        if(m2 == "January" && check == 2)
            lp--;
        if(m2 == "February" && d2 < 29 && check == 2)
            lp--;
            printf("Case %d: %d\n", i, lp);
      }
      return 0;
}
