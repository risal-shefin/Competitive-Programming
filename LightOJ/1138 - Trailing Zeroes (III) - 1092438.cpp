#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        int lo = 0, hi = INT_MAX, r = -1;
          while(lo <= hi) {
              int mid = lo / 2  + hi / 2, cnt = 0;
            int tmp = mid;
            while(tmp != 0) {
                tmp /= 5;
                cnt += tmp;
            }
              if(cnt == n) {
                r = mid;
                hi = mid - 1;
            }
              else if(cnt > n)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
          if(r != -1)
            printf("Case %d: %d\n", i , r);
        else
            printf("Case %d: impossible\n", i);
    }
      return 0;
}
 
