#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
ll dp[2][2][22][1 << 10][1 << 5];
vector <ll> num;
ll solve(ll isStart, ll isSmall, ll pos, ll bt, ll used)
 {
    if(pos == 0) {
        bool chk = 1;
        for(ll i = 0; i <= 9; i++) {
            if(!(i & 1) && !( (used >> (i / 2) ) & 1) )
                continue;
            if( (i & 1) && ( (bt >> i) & 1) ) {
                chk = 0;
                break;
            }
            if( !(i & 1) && !( (bt >> i) & 1) ) {
                chk = 0;
                break;
            }
        }
         return (ll)chk;
    }
    ll &ret = dp[isStart][isSmall][pos][bt][used];
    if(ret != -1 && isSmall)
        return ret;
     ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];
     ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, bt ^ (1 << i), !(i & 1) ? used | (1 << (i / 2)): used );
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, bt ^ (1 << i), !(i & 1) ? used | (1 << (i / 2)): used );
         rt += solve(1, 1, pos - 1, 0, 0);
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
        num.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());
     return solve(1, 0, num.size(), 0, 0) - 1;
}
int main()
 {
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll l, r;
        scanf("%llu %llu", &l, &r);
         ll ans = calc(r);
         ans -= calc(l - 1);
         printf("%llu\n", ans);
    }
     return 0;
