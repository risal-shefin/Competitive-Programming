#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pb push_back
#define inf 17446744073709551616
ll dp[2][2][2][22];
vector <ll> num;

ll solve(ll isStart, ll isSmall, ll isOne, ll pos)

{
    if(pos == 0)
        return 1;
    ll &ret = dp[isStart][isSmall][isOne][pos];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            if(isOne && i == 3)
                continue;
            rt += solve(0, isSmall | i < num[pos2], i == 1, pos - 1);
        }
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            rt += solve(0, isSmall | i < num[pos2], i == 1, pos - 1);
        }

        rt += solve(1, 1, 0, pos - 1);
    }

    return ret = rt;
}

ll calc(ll n)

{
    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());

    return solve(1, 0, 0, num.size()) - 1;
}

int main()

{
    freopen("hotel.in", "r", stdin);
    freopen("hotel.out", "w", stdout);

    ll t, caseno = 0, n;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        ll n;
        scanf("%llu", &n);

        ll lo = 1, hi = inf, ans;
        while(lo <= hi) {
            ll mid = lo + (hi - lo) / 2;

            ll tmp = calc(mid);
            //cout << mid << "  " << tmp << endl;
            if(tmp > n)
                hi = mid - 1;
            else if(tmp < n)
                lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }

        printf("%llu\n", ans);
    }

    return 0;
}