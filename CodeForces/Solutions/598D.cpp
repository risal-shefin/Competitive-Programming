#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[1009][1009];
bool vis[1009][1009], vis2[1009][1009];
ll n, m, k, dp[1009][1009];

ll dfs(ll r, ll c)

{
    if(r < 1 || c < 1 || r > n || c > m)
        return 0;
    if(grid[r][c] == '*')
        return 1;
    if(vis[r][c] == 1)
        return 0;

    vis[r][c] = 1;

    ll ret = 0;
    ret += dfs(r + 1, c);
    ret += dfs(r - 1, c);
    ret += dfs(r, c - 1);
    ret += dfs(r, c + 1);

    return ret;
}

void updatedfs(ll r, ll c, ll &val)

{
    if(r < 1 || c < 1 || r > n || c > m)
        return;
    if(vis2[r][c] == 1 || grid[r][c] == '*')
        return;

    vis2[r][c] = 1;
    dp[r][c] = val;

    ll ret = 0;
    updatedfs(r + 1, c, val);
    updatedfs(r - 1, c, val);
    updatedfs(r, c - 1, val);
    updatedfs(r, c + 1, val);
}

int main()

{
    cin >> n >> m >> k;

    for(ll i = 1; i <= n; i++)
        scanf("%s", grid[i] + 1);

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(grid[i][j] == '*' || vis[i][j] == 1)
                continue;

            ll ret = dfs(i, j);
            updatedfs(i, j, ret);
        }
    }

    for(ll i = 1; i <= k; i++) {
        ll r, c;
        scanf("%lld %lld", &r, &c);
        printf("%lld\n", dp[r][c]);
    }

    return 0;
}