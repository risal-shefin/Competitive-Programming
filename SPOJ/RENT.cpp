#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

struct node{
    ll l, r, c;
} ara[10009];

ll dp[10009], b[10009];

bool cmp(node a, node b)

{
    return a.l < b.l;
}

ll solve(ll indx)

{
    if(indx > n)
        return 0;
    if(dp[indx] != -1)
        return dp[indx];

    ll pos = upper_bound(b + 1, b + n + 1, ara[indx].r) - b;
    if(pos > 1) {
        if(b[pos - 1] == ara[indx].r)
            pos--;
    }

    return dp[indx] = max(solve(indx + 1), solve(pos) + ara[indx].c);
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld %lld", &ara[i].l, &ara[i].r, &ara[i].c);
            ara[i].r += ara[i].l;
            b[i] = ara[i].l;
        }

        sort(ara + 1, ara + n + 1, cmp);
        sort(b + 1, b + n + 1);

        printf("%lld\n", solve(1));
    }

    return 0;
}
