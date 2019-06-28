#include <stdio.h>
int main()
{
    int T, n, m, k, i, l, j, check1, check2, p;
    int ara[35][35], pr[35];
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d %d", &n, &m, &l);
        for(j = 0; j < n; j++) {
            for(k = 0; k < l; k++) {
                scanf("%d", &ara[j][k]);
            }
        }
                for(j = 0; j < 35; j++) {
            pr[j] = 0;
        }
                scanf("%d", &p);
        for(j = 0; j < p; j++) {
             scanf("%d", &k);
             pr[k] = 1;
        }
                check2 = 1;
        for(j = 0; j < n; j++) {
            check1 = 0;
            for(k = 0; k < l; k++) {
                if(ara[j][k] > 0 && pr[ara[j][k]] ==1) {
                    check1 = 1;
                }
                if(ara[j][k] < 0 && pr[-ara[j][k]] == 0) {
                     check1 = 1;
                }
            }
            if(check1 == 0)
                 check2 = 0;
        }
                if(check2 == 1)
             printf("Case %d: Yes\n", i);
        else
              printf("Case %d: No\n", i);
    }
        return 0;
}
