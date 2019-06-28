#include <stdio.h>
#include <math.h>
int main()
{
    long long int S, sqt, sq, sqt2, sq2, dif1, dif2, col, row;
    int T, i;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%lld", &S);
        sqt = ceil(sqrt(S));
        sqt2 = floor(sqrt(S));
        sq = sqt * sqt;
        sq2 = sqt2 * sqt2;
        dif1 = sq - S;
          if(sq % 2 != 0) {
            if(dif1 < sqt2) {
                col = dif1 + 1;
                row = sqt;
            }
            else if(dif1 == sqt2) {
                col = sqt;
                row = sqt;
            }
            else if(dif1 > sqt2) {
                col = sqt;
                row = S - sq2;
            }
        }
          else {
            if(dif1 > sqt2) {
                col = S - sq2;
                row = sqt;
            }
            else if(dif1 == sqt2) {
                col = sqt;
                row = sqt;
            }
            else if(dif1 < sqt2) {
                col = sqt;
                row = dif1 + 1;
            }
        }
          printf("Case %d: %lld %lld\n", i, col, row);
    }
      return 0;
}
 
