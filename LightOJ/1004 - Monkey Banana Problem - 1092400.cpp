#include <bits/stdc++.h>
using namespace std;
#define in long long int
in ara[205][105];
in ret[205][105];
long long int maxfind(in row, in col, in n)
{
    if(row == 2 * n)
        return 0;
    if(ret[row][col] != -1)
        return ret[row][col];
      if(row < n) {
        in sl = ara[row][col] + maxfind(row + 1, col, n);
        in sr = ara[row][col] + maxfind(row + 1, col + 1, n);
        return ret[row][col] = max(sl, sr);
    }
      if(row >= n) {
        if(col == 1) {
            return ret[row][col] = ara[row][col] + maxfind(row + 1, col, n);
        }
        else if(col == 2 * n - row) {
            return ret[row][col] = ara[row][col] + maxfind(row + 1, col - 1, n);
        }
          else {
            in sl = ara[row][col] + maxfind(row + 1, col - 1, n);
            in sr = ara[row][col] + maxfind(row + 1, col, n);
            return ret[row][col] = max(sl, sr);
        }
    }
}
int main()
{
    in t;
    scanf("%lld", &t);
    for(in i = 1; i <= t; i++) {
        in n, j;
        scanf("%lld", &n);
        for(j = 1; j <= 2 * n - 1; j++) {
              if(j < n) {
                for(in k = 1; k <= j; k++) {
                    scanf("%lld", &ara[j][k]);
                    ret[j][k] = -1;
                }
            }
              else {
                for(in k = 1; k <= 2 * n - j; k++) {
                    scanf("%lld", &ara[j][k]);
                    ret[j][k] = -1;
                }
            }
          }
          in mx = maxfind(1, 1, n);
        printf("Case %lld: %lld\n", i, mx);
    }
      return 0;
}
 
