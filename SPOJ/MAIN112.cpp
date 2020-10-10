#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[20], c[20], n;
ll dp[1 << 16][17];

ll solve(ll mask, ll prv, ll indx)

{
    if(indx > n)
        return 0;

    ll &ret = dp[mask][prv];
    if(ret != -1)
        return ret;

    ll add = 0, mx = 1e18;
    for(ll i = 1; i <= n; i++) {
        bool check = (mask >> i) & 1;
        if(check)
            continue;

        if(prv != 0)
            add = abs(ara[i] - ara[prv]) * c[indx];

        mx = min(mx, add + solve(mask | (1 << i), i, indx + 1) );
    }

    return ret = mx;
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &c[i]);

        printf("%lld\n", solve(0, 0, 1) );
    }

    return 0;
}
