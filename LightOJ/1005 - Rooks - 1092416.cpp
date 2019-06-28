#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, no = 0;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        long long unsigned way = 0;
        if(n * n >= k) {
            way = 1;
            for(int pown = 1; pown <= k; pown++) {
                way = (n * n * way) / pown;
                n--;
            }
        }
          printf("Case %d: %llu\n", ++no, way);
    }
      return 0;
}
 
