#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pb push_back
ll dp[9][2][2][9][1 << 16], t, cnt[17];
vector <ll> num;

ll solve(ll isStart, ll isSmall, ll pos, ll msk, ll sz)

{
    if(pos == 0) {
        //cout << msk << endl;
        return 1;
    }
    ll &ret = dp[sz][isStart][isSmall][pos][msk];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 15;
    else
        lim = num[pos2];

    ll rt = 0, msk2;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            if(cnt[i] == t)
                continue;

            msk2 = msk;
            if(cnt[i] == t - 1)
                msk2 |= (1 << i);
            cnt[i]++;
            rt += solve(0, isSmall | i < num[pos2], pos - 1, msk2, sz);
            cnt[i]--;
        }
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            if(cnt[i] == t)
                continue;

            msk2 = msk;
            if(cnt[i] == t - 1)
                msk2 |= (1 << i);
            cnt[i]++;
            rt += solve(0, isSmall | i < num[pos2], pos - 1, msk2, sz);
            cnt[i]--;
        }

        rt += solve(1, 1, pos - 1, 0, sz - 1);
    }

    return ret = rt;
}

ll calc(ll n)

{
    if(n < 0)
        return 0;

    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 16);
        tmp /= 16;
    }
    reverse(num.begin(), num.end());

    return solve(1, 0, num.size(), 0, num.size()) - 1;
}

int main()

{
    ll caseno = 0;
    memset(dp, -1, sizeof(dp));
    ll pos;
    cin >> pos >> t;

    //cout << calc(1269) << endl;

    ll lo = 1, hi = 2e9, ans;

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        ll rt = calc(mid);

        //cout << mid << "   " << rt << endl;
        if(rt > pos)
            hi = mid - 1;
        else if(rt == pos) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    //cout << ans << endl;

    memset(cnt, 0, sizeof(cnt));

    vector <ll> num2;
    ll tmp = ans;
    while(tmp) {
        num2.pb(tmp % 16);
        cnt[tmp % 16]++;
        tmp /= 16;
    }
    reverse(num2.begin(), num2.end());

    for(ll i = num2.size() - 1; i >= 0; i--) {
        if(cnt[ num2[i] ] > t) {
            for(ll j = 0; j <= 15; j++) {
                if(cnt[j] < t) {
                    cnt[ num2[i] ]--;
                    num2[i] = j;
                    cnt[j]++;
                    break;
                }
            }
        }
    }


    for(ll i = 0; i < num2.size(); i++) {
        if(num2[i] < 10)
            printf("%d", num2[i]);
        else {
            printf("%c", 'a' + (num2[i] % 10) );
        }
    }

    cout << endl;

    return 0;
}