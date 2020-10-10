#include <bits/stdc++.h>

using namespace std;

int ara[8];

int main()

{
    for(int i = 1; i <= 6; i++) {
        scanf("%d", &ara[i]);
    }

    int sum = 0;
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            for(int k = 1; k <= 6; k++) {
                if(i != k && k != j && j != i) {
                    sum = ara[i] + ara[j] + ara[k];

                    int tmp = 0;
                    for(int l = 1; l <= 6; l++) {
                        if(l != i && l != j && l != k)
                            tmp += ara[l];
                    }

                    if(sum == tmp) {
                        printf("YES\n");
                        return 0;
                    }
                }

            }
        }
    }

    printf("NO\n");

    return 0;
}