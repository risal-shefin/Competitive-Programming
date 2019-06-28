#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int n, l;
        long long k = 0;
        scanf("%d", &n);
        printf("Case %d:\n", i);
        for(int j = 1; j <= n; j++) {
            char s[10];
            scanf("%s", s);
            if(!strcmp(s, "report"))
                printf("%lld\n", k);
            else {
                scanf("%d", &l);
                k += l;
            }
        }
    }
      return 0;
}
