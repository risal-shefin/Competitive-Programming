
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
ll dp[2][2][52][52][52][52];
ll num[52], sz;
char l[55], r[55];

ll solve(ll isStart, ll isSmall, ll pos, ll cnt3, ll cnt6, ll cnt9)

{
    if(pos == 0) {
        if(cnt3 == cnt6 && cnt6 == cnt9 && cnt3 > 0)
            return 1;
        return 0;
    }
    ll &ret = dp[isStart][isSmall][pos][cnt3][cnt6][cnt9];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = sz - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i == 3) + cnt3, (i == 6) + cnt6, (i == 9) + cnt9);
            if(rt > mod)
                rt %= mod;
        }
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i == 3) + cnt3, (i == 6) + cnt6, (i == 9) + cnt9);
            if(rt > mod)
                rt %= mod;
        }

        rt += solve(1, 1, pos - 1, 0, 0, 0);
        if(rt > mod)
            rt %= mod;
    }

    return ret = rt;
}

int main()

{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        scanf("%s %s", l, r);

        sz = 0;
        for(ll i = 0; r[i] != '\0'; i++)
            num[sz++] = r[i] - '0';

        ll ans = solve(1, 0, sz, 0, 0, 0);
        ll len = strlen(l);

        ll mn = 1, nm;
        for(ll i = len - 1; i >= 0; i--) {
            nm = l[i] - '0';
            if(nm == 0) {
                l[i] = '9';
                mn = 1;
            }
            else {
                l[i] = (nm - 1) + '0';
                mn = 0;
            }

            if(mn == 0)
                break;
        }

        sz = mn = 0;
        for(ll i = 0; l[i] != '\0'; i++) {
            if(l[i] != '0')
                mn = 1;
            if(mn)
                num[sz++] = l[i] - '0';
        }

        ans -= solve(1, 0, sz, 0, 0, 0);
        ans = (ans + mod) % mod;

        printf("%lld\n",  ans);
    }

    return 0;
