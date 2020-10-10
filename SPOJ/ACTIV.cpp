#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000

ll dp[100009];

struct node {
    ll l, r;
} ara[100009];

bool operator <(node a, node b)

{
    if(a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}

ll n;

ll solve(ll i)

{
    if(i > n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    ll ret = solve(i + 1) % mod;
    node tmp = ara[i];
    ll pos = n + 1, lo = i + 1, hi = n;

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        if(ara[mid].l < ara[i].r)
            lo = mid + 1;
        else {
            pos = mid;
            hi = mid - 1;
        }
    }

    //cout << ara[i].r << "  " << ara[pos].r << endl;
    ret = (ret + 1 + solve(pos)) % mod;

    return dp[i] = ret;
}

int main()

{
    while(scanf("%lld", &n) && n != -1) {

        memset(dp, -1, sizeof(dp));

        for(ll i = 1; i <= n; i++)
            scanf("%lld %lld", &ara[i].l, &ara[i].r);

        sort(ara + 1, ara + n + 1);

        ll ans = solve(1);

        ll num = ans, cnt = 0;
        if(num == 0)
            cnt++;
        while(num != 0) {
            num /= 10;
            cnt++;
        }

        ll rem = 8 - cnt;
        for(ll i = 1; i <= rem; i++)
            printf("0");

        printf("%lld\n", ans);
    }

    return 0;
}
