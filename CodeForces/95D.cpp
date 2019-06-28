#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
ll dp[2][2][1010][1010][2], k;
string num, numl, numr;
ll solve(ll isStart, ll isSmall, ll pos, ll last, ll isLucky)
{
    if(pos == 0)
        return isLucky;
    ll &ret = dp[isStart][isSmall][pos][last][isLucky];
    if(ret != -1 && isSmall)
        return ret;
    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2] - '0';
    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            ll nlast = last;
            bool tmp = 0;
            if(i == 4 || i == 7) {
                if(last != 1008 && abs(last - pos) <= k)
                    tmp = 1;
                nlast = pos;
            }
            rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, nlast, isLucky | tmp);
        }
        rt %= mod;
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            ll nlast = last;
            bool tmp = 0;
            if(i == 4 || i == 7) {
                if(last != 1008 && abs(last - pos) <= k)
                    tmp = 1;
                nlast = pos;
            }
            rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, nlast, isLucky | tmp);
        }
        rt += solve(1, 1, pos - 1, 1008, 0);
        rt %= mod;
    }
    return ret = rt % mod;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t >> k;
    while(t--) {
        cin >> numl >> numr;
        ll carry = 1;
        for(ll i = (ll)numl.length() - 1; i >= 0; i--) {
            if(numl[i] == '0') {
                numl[i] = '9';
                carry = 1;
            }
            else {
                numl[i] = (numl[i] - '1') + '0';
                break;
            }
        }
        num = numr;
        ll ans = solve(1, 0, num.length(), 1008, 0);
        num = "";
        bool chk = 0;
        for(ll i = 0; i < numl.length(); i++) {
            if(numl[i] != '0')
                chk = 1;
            if(chk)
                num += numl[i];
        }
        if(num.length() != 0)
            ans -= solve(1, 0, num.length(), 1008, 0);
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
