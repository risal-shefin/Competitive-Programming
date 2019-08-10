///How many zeros in the numbers' digits. Range of the numbers is (l, r)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][2][12][12];
vector <ll> num;

ll solve(ll isStart, ll isSmall, ll pos, ll val)

{
    if(pos == 0)
        return val;
    ll &ret = dp[isStart][isSmall][pos][val];
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
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i == 0) + val);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, val);

        rt += solve(1, 1, pos - 1, 0);
    }

    return ret = rt;
}

ll calc(ll n)

{
    if(n < 0)
        return 0;
    if(n < 10)
        return 1;

    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());

    return solve(1, 0, num.size(), 0) + 1;    /// + 1 is for the number "0". We are not calculating this number in solve function.
}

int main()

{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);

        ll ans = calc(r);

        ans -= calc(l - 1);

        printf("Case %lld: %lld\n", ++caseno, ans);
    }

    return 0;
}
