#include <bits/stdc++.h>
using namespace std;

int main()

{
    int ara[4];
    scanf("%d %d %d %d", &ara[0], &ara[1], &ara[2], &ara[3]);

    for(int i = ara[0]; i <= 2 * ara[0]; i++) {

        for(int j = ara[1]; j < i && j <= 2 * ara[1]; j++) {

            for(int k = ara[2]; k < j && k <= 2 * ara[2]; k++) {

                if(ara[3] <= k && 2 * ara[3] >= k && 2 * ara[3] < j) {
                    printf("%d\n%d\n%d\n", i, j, k);
                    return 0;
                }

            }
        }
    }

    printf("-1\n");

    return 0;
}