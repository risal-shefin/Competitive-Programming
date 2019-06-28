#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL << 60)
ll ara[300009], dp[300009][20], last[20];
int main()
{
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j < 20; j++)
            dp[i][j] = inf;
    }
    for(ll i = n; i >= 1; i--) {
        for(ll j = 0; j < 20; j++) {
            if(!((ara[i] >> j) & 1))
                continue;
            for(ll k = 0; k < 20 && last[j] != 0; k++)
                dp[i][k] = min(dp[i][k], dp[ last[j] ][k]);
            last[j] = i;
            dp[i][j] = i;
        }
    }
    while(q--) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        bool ans = 0;
        for(ll i = 0; i < 20; i++) {
            if(!((ara[v] >> i) & 1))
                continue;
            if(dp[u][i] <= v) {
                ans = 1;
                break;
            }
        }
        if(ans)
            printf("Shi\n");
        else
            printf("Fou\n");
    }
    return 0;
}
