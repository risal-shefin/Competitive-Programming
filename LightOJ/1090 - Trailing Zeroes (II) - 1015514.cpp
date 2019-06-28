#include <bits/stdc++.h>
using namespace std;
#define siz 1000000
long long t[siz + 10];
long long f[siz + 10];
int main()
{
    for(int i = 2; i <= siz; i++) {
        int j = i;
        int temp = 0;
          while(j % 2 == 0) {
            j /= 2;
            temp++;
        }
        t[i] = t[i - 1] + temp;
          temp = 0;
        while(j % 5 == 0) {
            j /= 5;
            temp++;
        }
        f[i] = f[i - 1] + temp;
    }
      int T;
    scanf("%d", &T);
      for(int i = 1; i <= T; i++) {
        int n, r, p, q, n2, n5;
        scanf("%d %d %d %d", &n, &r, &p, &q);
        n2 = (t[p] - t[p - 1]) * q + t[n] - t[r] - t[n - r];
        n5 = (f[p] - f[p - 1]) * q + f[n] - f[r] - f[n - r];
        r = min(n2, n5);
          printf("Case %d: %d\n", i, r);
    }
      return 0;
}
 
