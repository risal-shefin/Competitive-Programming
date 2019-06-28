#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100009], n, dp[5009][5009];
ll solve(ll pos, ll last)
 {
    if(pos > n)
        return 0;
    ll &ret = dp[pos][last];
    if(ret != -1)
        return ret;
     ret = 0;
    if(last == 0 || ( abs(ara[last]) < abs(ara[pos]) && ( (ara[last] < 0 && ara[pos] > 0) || (ara[last] > 0 && ara[pos] < 0) ) ) )
        ret = 1 + solve(pos + 1, pos);
     ret = max(ret, solve(pos + 1, last));
     return ret;
}
int main()
 {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);
     cout << solve(1, 0) << endl;
     return 0;
