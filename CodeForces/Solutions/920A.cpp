#include <bits/stdc++.h>
using namespace std;

#define ll long long

int ara[209];

int main()

{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &ara[i]);
        }

        int time;
        for(int i = 0; i < k; i++) {
            if(i == 0) {
                time = ara[i];
            }
            if(i == k - 1) {
                time = max(time, n - ara[i] + 1);
            }

            if(i != k - 1) {
                int tmp = ara[i + 1] - ara[i];
                tmp = tmp / 2 + 1;
                time = max(time, tmp);
            }
        }

        printf("%d\n", time);
    }

    return 0;
}