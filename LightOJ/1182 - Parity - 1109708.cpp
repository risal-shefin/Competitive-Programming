#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        long long int x = 1, cnt = 0;
          while(x <= n) {
            if(n & x)
                cnt++;
              x = x << 1;
        }
          printf("Case %d: ", ++caseno);
        if(cnt % 2 == 0)
          printf("even\n");
        else
            printf("odd\n");
    }
      return 0;
}
 
