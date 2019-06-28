#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[109][10009], in[109], n, m;
ll mxself[109][109], tot[109], pre[109][109], suf[109][109];
ll solve(ll indx, ll rem)
{
    if(indx > n || rem == 0)
        return 0;
    if(dp[indx][rem] != -1)
        return dp[indx][rem];
    dp[indx][rem] = solve(indx + 1, rem);
    for(ll i = 1; i <= min(rem, tot[indx] ); i++) {
        dp[indx][rem] = max(dp[indx][rem], mxself[indx][i] + solve(indx + 1, rem - i) );
    }
    return dp[indx][rem];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &tot[i]);
        for(ll j = 1; j <= tot[i]; j++) {
            scanf("%lld", &in[j]);
            pre[i][j] = in[j] + pre[i][j - 1];
        }
        for(ll j = tot[i]; j >= 1; j--) {
            suf[i][j] = in[j] + suf[i][j + 1];
        }
        for(ll j = 1; j <= tot[i]; j++) {
            ll nai = tot[i] - j;
            for(ll k = 1; k + nai - 1 <= tot[i]; k++) {
                mxself[i][j] = max(mxself[i][j], pre[i][k - 1] + suf[i][k + nai]);
            }
        }
    }
    ll ans = solve(1, m);
    printf("%lld\n", ans);
    return 0;
}
