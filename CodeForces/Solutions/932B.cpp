#include <bits/stdc++.h>

using namespace std;

#define ll long long

int dp[1000009];
int cum[11][1000009];

int func(int n)

{
    if(dp[n] != -1)
        return dp[n];
    if(n < 10)
        return dp[n] = n;
    int tmp = n;
    int ret = 1;
    while(tmp != 0) {
        int tp = tmp % 10;
        if(tp != 0)
            ret = ret * tp;
        tmp /= 10;
    }

    return dp[n] = func(ret);
}

int main()

{
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= 1000000; i++)
        func(i);

    for(int i = 1; i <= 1000000; i++) {
        if(dp[i] != -1) {
            cum[ dp[i] ][i] = 1;
        }
        for(int j = 1; j <= 9; j++) {
            cum[j][i] += cum[j][i - 1];
        }
    }
    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", cum[k][r] - cum[k][l - 1]);
    }
    return 0;
}