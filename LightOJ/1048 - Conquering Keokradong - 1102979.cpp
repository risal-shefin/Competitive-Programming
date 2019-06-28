#include <bits/stdc++.h>
using namespace std;
int n, k, dist[1005];
bool is(int dst)
{
    int partrem = n + 1;
    int dayrem = k + 1;
    int indx = 0;
      while(dayrem >= 1) {
        int go = dist[indx++];
        dayrem--;
        partrem--;
        while(partrem > dayrem && go + dist[indx] <= dst) {
            partrem--;
            if(dayrem == partrem) return true;
            go += dist[indx++];
        }
    }
      return partrem == dayrem;
}
int bsearch(int lo, int hi)
{
    int d;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
          if(is(mid)) {
            d = mid;
            hi = mid - 1;
        }
          else
            lo = mid + 1;
    }
      return d;
}
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        int sum = 0, mx = -63;
        for(int i = 0; i <= n; i++) {
            scanf("%d", &dist[i]);
            sum += dist[i];
            mx = max(mx, dist[i]);
        }
          int d = bsearch(mx, sum);
        printf("Case %d: %d\n", ++caseno, d);
        int day = k + 1;
        int part = n + 1;
        int indx = 0;
        while(day >= 1) {
            int go = dist[indx++];
            day--;
            part--;
            while(part > day && go + dist[indx] <= d) {
                part--;
                go += dist[indx++];
            }
              printf("%d\n", go);
        }
    }
      return 0;
}
 
