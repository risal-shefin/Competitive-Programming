#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair <ll, ll>
ll col[105];
pll dp[105][105];
pll solve(ll i, ll j)
 {
    if(i == j)
        return pll(col[i], 0);
    if(dp[i][j].first != -1)
        return dp[i][j];
     ll ret = 1e18, col;
    for(ll k = i; k < j; k++) {
        pll p1 = solve(i, k);
        pll p2 = solve(k + 1, j);
         if(p1.second + p2.second + (p1.first * p2.first) < ret) {
            ret = p1.second + p2.second + (p1.first * p2.first);
            col = (p1.first + p2.first) % 100;
        }
        else if(p1.second + p2.second + (p1.first * p2.first) == ret) {
            if( (p1.first + p2.first) % 100 < col)
                col = (p1.first + p2.first) % 100;
        }
    }
     return dp[i][j] = pll(col, ret);
}
int main()
 {
    ll n, in;
    while(scanf("%lld", &n) != EOF) {
         for(ll i = 0; i <= 102; i++)
            for(ll j = 0; j <= 102; j++)
                dp[i][j].first = -1, dp[i][j].second = -1;
         for(ll i = 1; i <= n; i++)
            scanf("%lld", &col[i]);
         pll p = solve(1, n);
        printf("%lld\n", p.second);
    }
    return 0;
}
