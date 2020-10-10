#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> dv[62];
ll dp[62];

ll check(ll l, ll r, ll n, ll len, ll block)

{
    ll lo = l, hi = r, ret = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll shift = len / block, tmp = 0;
        for(ll i = 1; i <= shift; i++)
            tmp = (tmp << block) + mid;

        if(tmp <= n) {
            ret = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    if(ret == -1)
        return 0;
    else
        return (ret - l + 1);
}

ll solve(ll n)

{
    if(n == 0) return 0;

    memset(dp, 0, sizeof(dp));

    ll tmp = n, len = 0;
    while(tmp) {
        tmp /= 2;
        len++;
    }

    ll prv = 0, now, tot = 0;
    for(ll k = 1; k <= len / 2; k++) {
        now = (1LL << k) - 1;
        dp[k] = now - prv;

        for(ll i = 0; i < dv[k].size(); i++)
            dp[k] -= dp[dv[k][i]];

        prv = now;
    }

    for(ll i = 1; i < len; i++) {
        for(ll j = 0; j < dv[i].size(); j++)
            tot += dp[dv[i][j]];
    }

    memset(dp, 0, sizeof(dp));
    for(ll i = 0; i < dv[len].size(); i++) {
        ll num = dv[len][i];
        now = (1LL << num) - 1, prv = 1LL << (num - 1);
        ll valid = check(prv, now, n, len, num);
        //cout << num << "  " << valid << "  " << prv << "  " << now << endl;
        dp[num] = valid;

        for(ll num2: dv[num])
            dp[num] -= dp[num2];

        tot += dp[num];
    }

    return tot;
}

int main()

{
    for(ll i = 1; i <= 60; i++) {
        for(ll j = 1; j < i; j++) {
            if(i % j == 0)
                dv[i].push_back(j);
        }
    }

    ll l, r;
    cin >> l >> r;

    cout << solve(r) - solve(l - 1) << endl;

    return 0;
}