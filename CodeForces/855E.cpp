#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[9][2][2][67][1 << 10], base;
vector <ll> num;
ll solve(ll isStart, ll isSmall, ll pos, ll bt)
{
    if(pos == 0) {
        bool chk = 1;
        for(ll i = 0; i < base; i++)
            if( (bt >> i) & 1) {
                chk = 0;
                break;
            }
        return (ll)chk;
    }
    ll &ret = dp[base - 2][isStart][isSmall][pos][bt];
    if(ret != -1 && isSmall)
        return ret;
    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = base - 1;
    else
        lim = num[pos2];
    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, bt ^ (1 << i));
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, bt ^ (1 << i));
        rt += solve(1, 1, pos - 1, 0);
    }
    return ret = rt;
}
ll calc(ll n)
{
    if(n <= 0)
        return 0;
    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % base);
        tmp /= base;
    }
    reverse(num.begin(), num.end());
    return solve(1, 0, num.size(), 0) - 1;
}
int main()
{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll l, r;
        scanf("%lld %lld %lld", &base, &l, &r);
        ll ans = calc(r);
        ans -= calc(l - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
