#include <bits/stdc++.h>
using namespace std;
#define ll int
ll n, ara[100009], dp[100009][320];
ll solve(ll p, ll k)
{
    if(p > n) return 0;
    if(dp[p][k] != 0) return dp[p][k];
    dp[p][k] = 1 + solve(p + ara[p] + k, k);
    return dp[p][k];
}
int main()
{
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= 317; j++)
            dp[i][j] = solve(i, j);
    }
    ll q;
    cin >> q;
    while(q--) {
        ll p, k;
        scanf("%d %d", &p, &k);
        if(k <= 317)
            printf("%d\n", dp[p][k]);
        else {
            ll ans = 0;
            while(p <= n) {
                p += ara[p] + k;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
