#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll after[1009][1009];
ll perm[6][1009], dp[1009][1009], n, k;
ll solve(ll pos, ll num)
{
    if(pos > n)
        return 0;
    ll &ret = dp[pos][num];
    if(ret != -1)
        return ret;
    ret = 0;
    for(ll i = 1; i <= n; i++) {
        if(pos == 1)
            ret = max(ret, 1 + solve(pos + 1, i));
        else {
            if(after[num][i] == k)
                ret = max(ret, 1 + solve(pos + 1, i));
        }
    }
    return ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for(ll i = 1; i <= k; i++) {
        for(ll j = 1; j <= n; j++) {
            scanf("%lld", &perm[i][j]);
        }
    }
    for(ll i = 1; i <= k; i++) {
        for(ll j = 1; j <= n; j++) {
            for(ll p = j + 1; p <= n; p++) {
                ll num1 = perm[i][j], num2 = perm[i][p];
                after[num1][num2]++;
            }
        }
    }
    cout << solve(1, 0) << endl;
    return 0;
}
