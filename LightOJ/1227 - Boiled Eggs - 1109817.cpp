#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
      while(t--) {
        int N, P, Q, w, sumw = 0, cnt = 0;
        scanf("%d %d %d", &N, &P, &Q);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &w);
            sumw += w;
            if(sumw <= Q && i <= P)
                cnt++;
        }
          printf("Case %d: %d\n", ++caseno, cnt);
    }
      return 0;
}
   
