#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000

ll ara[200009], n, dp[200009][2];
bool vis[200009][2];

ll dfs(ll u, bool state)

{
    if(u <= 0 || u > n)
        return 0;
    if(u == 1) {
        if(state == 1) return 0;
        else return -1;
    }
    if(vis[u][state]) {
        if(dp[u][state] == -inf)
            return -1;
        else
            return dp[u][state];
    }

    vis[u][state] = 1;
    ll ret = 0;
    if(!state)
        ret = dfs(u + ara[u], state ^ 1);
    else
        ret = dfs(u - ara[u], state ^ 1);

    if(ret != -1)
        dp[u][state] = ara[u] + ret;
    else
        dp[u][state] = -1;

    return dp[u][state];
}

int main()

{
    for(ll i = 0; i <= 200002; i++) {
        for(ll j = 0; j < 2; j++)
            dp[i][j] = -inf;
    }

    cin >> n;
    for(ll i = 2; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 2; i <= n; i++) {
        if(!vis[i][0])
            dfs(i, 0);
        if(!vis[i][1])
            dfs(i, 1);
    }

    for(ll i = 1; i < n; i++) {
        if(dp[i + 1][1] != -1) {
            printf("%lld\n", dp[i + 1][1] + i);
        }
        else
            printf("-1\n");
    }

    return 0;
}