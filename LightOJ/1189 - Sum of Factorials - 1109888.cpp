#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long fact[23], i, f = 1;
    fact[0] = 1;
    for(i = 1; i <= 19; i++)  {
        f *= i;
        fact[i] = f;
    }
      int t, caseno = 0;
    scanf("%d", &t);
      while(t--) {
        long long n;
        scanf("%lld", &n);
        long long ans[23];
        int indx = 0;
          for(i = 19; i >= 0; i--) {
            if(fact[i] <= n) {
                ans[indx++] = i;
                n -= fact[i];
            }
            if(n <= 0)
                break;
        }
          if(n != 0)
            printf("Case %d: impossible\n", ++caseno);
        else {
            printf("Case %d: ", ++caseno);
            for(int j = indx - 1; j >= 0; j--) {
                printf("%d!", ans[j]);
                if(j != 0)
                    printf("+");
            }
            printf("\n");
        }
    }
    return 0;
}
 
