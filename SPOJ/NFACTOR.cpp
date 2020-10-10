#include <bits/stdc++.h>

using namespace std;

#define siz 1000000

int coun[siz + 5];
char mark[siz + 5];

struct ab {
    int pf[11];
}num[siz + 5];

int main()

{
    for(int i = 2; i <= siz; i++) {
        if(mark[i] == '\0') {
            for(int j = i + i; j <= siz; j += i) {
                mark[j] = '1';
                coun[j]++;
            }
            coun[i]++;
        }
    }

    for(int i = 1; i <= siz; i++) {
        for(int j = 1; j <= 7; j++)
            num[i].pf[j] = num[i - 1].pf[j];

        num[i].pf[coun[i]]++;
    }

    int T, a, b, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &a, &b, &n);

        if(n == 0 && a == 1) {
                printf("1\n");
        }

        else {
            printf("%d\n", num[b].pf[n] - num[a - 1].pf[n]);
        }
    }

    return 0;
}
