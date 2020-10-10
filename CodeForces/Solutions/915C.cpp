#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][20][1 << 18], dg[20], mark[20];
vector <ll> num;
ll a, b;
string sa, sb;

ll solve(ll isStart, ll isSmall, ll pos, ll bt, ll val)

{
    if(pos == 0)
        return val;
    ll &ret = dp[isSmall][pos][bt];
    if(ret != -1) {
        //cout << pos << "  " << ret << endl;
        return ret;
    }

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 9;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = sa.length() - 1; i >= 0; i--) {
            if(dg[i] > lim)
                continue;
            if( (bt >> i) & 1)
                continue;
            rt = max(rt, solve(0, isSmall | dg[i] < num[pos2], pos - 1, bt | (1 << i), val * 10 + dg[i] ) );
        }
    }
    else {
        for(ll i = sa.length() - 1; i >= 0; i--) {
            if(dg[i] > lim)
                continue;
            if(dg[i] == 0)
                continue;
            if( (bt >> i) & 1)
                continue;

            //cout << num[pos2] << " " << pos - 1 << endl;
            rt = max(rt, solve(0, isSmall | dg[i] < num[pos2], pos - 1, bt | (1 << i), val * 10 + dg[i] ) );
            //cout << dg[i] << "  " << rt << " " << val * 10 + dg[i] << " " << ( bt | (1 << i) ) << endl;
        }
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

    return solve(1, 0, num.size(), 0, 0);
}

int main()

{
    memset(dp, -1, sizeof(dp));

    cin >> sa >> sb;

    if(sb.length() > sa.length()) {
        sort(sa.begin(), sa.end(), greater <char> () );
        cout << sa << endl;
    }
    else {
        stringstream ss(sa);
        ss >> a;
        stringstream ss2(sb);
        ss2 >> b;

        for(ll i = 0; i < sa.length(); i++)
            dg[i] = sa[i] - '0';

        sort(dg, dg + sa.length());
        cout << calc(b) << endl;
    }

    return 0;
}