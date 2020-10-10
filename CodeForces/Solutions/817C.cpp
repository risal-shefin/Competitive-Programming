#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][2][20][200], now;
vector <ll> num;

ll solve(ll isStart, ll isSmall, ll pos, ll val)

{
    if(pos == 0)
        return val == now;
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
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + val);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + val);

        rt += solve(1, 1, pos - 1, 0);
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

    return solve(1, 0, num.size(), 0);
}

int main()

{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    ll n, s;
    cin >> n >> s;

    ll tmp = n, len = 0, nsm = 0;
    while(tmp) {
        nsm += (tmp % 10);
        tmp /= 10;
        len++;
    }

    ll cnt = 0, l;
    for(ll i = 1; i <= 171; i++) {
        memset(dp, -1, sizeof(dp));
        now = i;
        l = s + i;
        if(l > n)
            continue;
        ll right = calc(n);
        ll left = calc(l - 1);

        //cout << l << "  " << i << "  " << left << "  " << right << endl;

        cnt += (right - left);
    }

    cout << cnt << endl;

    return 0;
}