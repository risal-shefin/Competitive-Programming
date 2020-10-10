#include <bits/stdc++.h>
using namespace std;

int dp[1000001], n, k, l, m, i;

int solve(int c)

{
    if(c < 0)
        return 0;

    if(dp[c] != -1) {
        //cout << c << "  " <<  dp[c] << endl;
        return !dp[c];
    }

    return dp[c] = solve(c - 1) | solve(c - k) | solve(c - l);
}

int main()

{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    scanf("%d %d %d", &k, &l, &m);
    for(i = 2; i <= 1000000; i++) {
        /*if(i - 1 >= 0)
            dp[i] |= !dp[i - 1];
        if(i - k >= 0)
            dp[i] |= !dp[i - k];
        if(i - l >= 0)
            dp[i] |= !dp[i - l];*/
        solve(i);
    }

    for(i = 1; i <= m; i++) {
        scanf("%d", &n);
        if(dp[n])
            printf("A");
        else
            printf("B");
    }
    return 0;
}
