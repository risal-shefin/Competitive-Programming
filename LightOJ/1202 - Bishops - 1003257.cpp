#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if((r1 & 1) == (r2 & 1)) {
            if((c1 & 1) != (c2 & 1)) {
                printf("Case %d: impossible\n", i);
                continue;
            }
        }
        else {
            if((c1 & 1) == (c2 & 1)) {
                printf("Case %d: impossible\n", i);
                continue;
            }
        }
          printf("Case %d: ", i);
        if(abs(r2 - r1) == abs(c2 - c1))
            printf("1\n");
        else
            printf("2\n");
    }
      return 0;
}
 
