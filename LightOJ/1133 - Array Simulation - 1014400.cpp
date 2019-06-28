#include <bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   scanf("%d", &T);
     for(int i = 1; i <= T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n], nm, nm2;
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[j - 1]);
        }
          string sm, sc;
        cin.ignore();
        for(int j = 1; j <= m; j++) {
            getline(cin, sm);
              stringstream ss(sm);
            ss >> sc;
            if(sc == "S") {
                ss >> nm;
                for(int k = 1; k <= n; k++) {
                    a[k - 1] += nm;
                }
            }
            else if(sc == "M") {
                ss >> nm;
                for(int k = 1; k <= n; k++) {
                    a[k - 1] *= nm;
                }
            }
              else if(sc == "D") {
                ss >> nm;
                for(int k = 1; k <= n; k++) {
                    a[k - 1] /= nm;
                }
            }
              else if(sc == "R") {
                reverse(a, a + n);
            }
              else if(sc == "P") {
                ss >> nm >> nm2;
                swap(a[nm], a[nm2]);
            }
        }
        printf("Case %d:\n", i);
        for(int j = 1; j <= n; j++) {
            printf("%d", a[j - 1]);
            if(j != n)
                printf(" ");
            else
                printf("\n");
        }
   }
     return 0;
}
 
