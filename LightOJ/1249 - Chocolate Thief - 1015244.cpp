#include <bits/stdc++.h>
using namespace std;
struct ab {
    char nm[30];
    long long int vl;
};
int main()
{
    int T;
    scanf("%d", &T);
    for(int  i = 1; i<= T; i++) {
        int n, l, w, h;
        long long vol;
        char name[30], nm[30], nm2[30];
        scanf("%d", &n);
        ab choc[n];
        for(int j = 1; j <= n; j++) {
            scanf("%s %d %d %d", name, &l, &h, &w);
            vol = l * h * w;
            choc[j - 1].vl = vol;
            strcpy(choc[j - 1].nm, name);
        }
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int j = 0; j < n; j++) {
            if(mn > choc[j].vl) {
                mn = choc[j].vl;
                strcpy(nm, choc[j].nm);
            }
              if(mx < choc[j].vl) {
                mx = choc[j].vl;
                strcpy(nm2, choc[j].nm);
            }
        }
          if(mn == mx)
            printf("Case %d: no thief\n", i);
        else
            printf("Case %d: %s took chocolate from %s\n", i, nm2, nm);
    }
      return 0;
}
