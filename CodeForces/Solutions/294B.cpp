#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll t, w;
} ara[105];

ll dp[209][209][209], tw = 0, tt = 0;

ll solve(ll t, ll pos, ll w)

{
    if(w > tt)
        return 1e15;
    if(pos == 0) {
        //cout << t << "  " << "  " << pos << "  " <<  w << endl;
        if(w <= t)
            return 0;
        else
            return 1e15;
    }

    ll &ret = dp[t][pos][w];
    if(ret != -1)
        return ret;

    ll rt = 1e15;
    rt = solve(t, pos - 1, w + ara[pos].w);
    rt = min(rt, ara[pos].t + solve(t + ara[pos].t, pos - 1, w));

    return ret = rt;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &ara[i].t, &ara[i].w);
        tw += ara[i].w;
        tt += ara[i].t;
    }

    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, n, 0);

    cout << ans << endl;

    return 0;
}