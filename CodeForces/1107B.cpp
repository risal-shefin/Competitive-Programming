#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[2][2][20][173][10];
vector <ll> root[12];
ll num[20], sz = 0;
ll dgroot(ll n)
{
    ll ret = 0;
    while(n) {
        ret += (n % 10);
        n /= 10;
        if(n == 0 && ret > 9) {
            n = ret;
            ret = 0;
        }
    }
    return ret;
}
ll solve(ll isStart, ll isSmall, ll pos, ll sum, ll x)
{
    if(pos == 0)
        return dgroot(sum) == x;
    ll &ret = dp[isStart][isSmall][pos][sum][x];
    if(ret != -1 && isSmall)
        return ret;
    ll lim, pos2 = sz - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];
    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + sum, x);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + sum, x);
        rt += solve(1, 1, pos - 1, 0, x);
    }
    return ret = rt;
}
ll calc(ll n, ll x)
{
    ll tmp = n;
    sz = 0;
    while(tmp) {
        num[sz++] = (tmp % 10);
        tmp /= 10;
    }
    reverse(num, num + sz);
    return solve(1, 0, sz, 0, x);
}
int main()
{
//    for(ll i = 1; i <= 171; i++) {
//        ll rt = dgroot(i);
//        root[rt].pb(i);
//    }
//
//    for(ll i = 1; i <= 9; i++)
//        sort(root[i].begin(), root[i].end());
    ll q;
    cin >> q;
    memset(dp, -1, sizeof(dp));
    while(q--) {
        ll x, k;
        scanf("%lld %lld", &k, &x);
        ll lo = 1, hi = 1e18, ans;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll rgt = calc(mid, x);
//            for(ll i = 0; i < root[x].size(); i++) {
//                rgt += calc(mid, root[x][i]);
//            }
            //cout <<  mid << "  " << rgt << endl;
            if(rgt >= k) {
                hi = mid - 1;
                ans = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
