#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long long ll;
typedef pair<ll,ll> lll;
typedef pair<ll,int> lli;
typedef pair<int,int> ii;
#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define mod 1000000007
ll dp[2][2][1005][1005], k;
vector <ll> num;
ll solve(ll isStart, ll isSmall, ll pos, ll val)
{
    if(pos == 0) {
        if(val == 0)
            return 0;
        ll step = 1;
        while(val != 1) {
            ll tmp = val, cnt1 = 0;
            while(tmp) {
                cnt1 += (tmp % 2);
                tmp /= 2;
            }
            val = cnt1;
            step++;
        }
        //cout << val << endl;
        return (step == k);
    }
    ll &ret = dp[isStart][isSmall][pos][val];
    if(ret != -1 && isSmall)
        return ret;
    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 1;
    else
        lim = num[pos2];
    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            //cout << i << "  " << val << "  " << pos << endl;
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i == 1) + val);
            rt %= mod;
        }
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            //cout << i << "  " << pos << endl;
            rt += solve(0, isSmall | i < num[pos2], pos - 1, (i == 1) + val);
            rt %= mod;
        }
        rt += solve(1, 1, pos - 1, 0);
        rt %= mod;
    }
    return ret = rt;
}
ll calc(string &n)
{
    num.clear();
    for(ll i = 0; i < n.length(); i++)
        num.pb(n[i] - '0');
    return solve(1, 0, num.size(), 0) - (k == 1);
}
int main()
{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s >> k;
    if(k == 0) {
        cout << 1 << endl;
        return 0;
    }
//    if(s == "1") {
//        if(k == 0)
//            cout << 1 << endl;
//        else
//            cout << 0 << endl;
//
//        return 0;
//    }
    cout << calc(s) << endl;
    return 0;
}
