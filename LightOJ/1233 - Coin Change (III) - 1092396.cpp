#include <bits/stdc++.h>
using namespace std;
bitset <100009> make;
int coin[110], num[110], numcn[100009];
int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
          for(int j = 1; j <= n; j++)
            scanf("%d", &coin[j]);
        for(int j = 1; j <= n; j++)
            scanf("%d", &num[j]);
          for(int k = 1; k <= m; k++) {
            make[k] = 0;
            numcn[k] = 0;
        }
        make[0] = 1;
        numcn[0] = 0;
        int cnt = 0;
          for(int j = 1; j <= n; j++) {
            for(int k = coin[j]; k <= m; k++) {
                if(make[k] == 0 && make[k - coin[j]] == 1 && numcn[k - coin[j]] + 1 <= num[j]) {
                    make[k] = 1;
                    cnt++;
                    numcn[k] = numcn[k - coin[j]] + 1;
                }
            }
          for(int j = 0; j <= m; j++)
            numcn[j] = 0;
          }
          printf("Case %d: %d\n", i, cnt);
      }
      return 0;
}
 
