#include <bits/stdc++.h>
using namespace std;
#define siz 1000009
double ara[siz];
int main()
{
    int T;
    scanf("%d", &T);
      double r;
      for(int i = 1; i < siz; i++)
        ara[i] = ara[i - 1] + log(i+0.0);
      for(int i = 1; i <= T; i++) {
        int n, b;
        scanf("%d %d", &n, &b);
          r = floor(ara[n]/log(b*1.0)) + 1;
          printf("Case %d: %0.0lf\n", i, r);
    }
      return 0;
}
 
