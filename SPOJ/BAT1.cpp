#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[25][25][1009], n, m;
ll open[25], cost[25][25], rat[25][25];

ll solve(ll i, ll j, ll k)

{
    if(i > n)
        return 0;
    if(k == 0)
        return 0;
    if(j > m)
        return solve(i + 1, 0, k);

    ll &rt = dp[i][j][k];
    if(rt != -1)
        return rt;

    ll ret = 0;
    if(j == 0) {
        ret = solve(i + 1, 0, k);
        if(k >= open[i])
            ret = max(ret, solve(i, j + 1, k - open[i]));

        return rt = ret;
    }

    for(ll cnt = 0; k - cnt * cost[i][j] >= 0; cnt++)
        ret = max(ret, solve(i, j + 1, k - cnt * cost[i][j] ) + cnt * rat[i][j] );

    return rt = ret;
}

int main()

{
    ll t, k;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));

        scanf("%lld %lld %lld", &n, &m, &k);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &open[i]);

        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++)
                scanf("%lld", &cost[i][j]);
        }

        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++)
                scanf("%lld", &rat[i][j] );
        }

        printf("%lld\n", solve(1, 0, k));
    }

    return 0;
}
