#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
ll dp[2][2][2002][2002][2], m, d;
string num;

ll solve(ll isStart, ll isSmall, ll pos, ll ns, ll dgc)

{
    if(pos == 0) {
        if(ns == 0)
            return 1;
        else
            return 0;
    }

    ll &ret = dp[isStart][isSmall][pos][ns][dgc];
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
            if( !dgc && i != d)
                continue;
            if( dgc && i == d)
                continue;
            //cout << (ns * 10 + i) % m << endl;
            rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, (ns * 10 + i) % m , dgc ^ 1);
            rt %= mod;
        }
    }
    else {
        for(ll i = 1; i <= lim; i++) {
            if(i == d)
                continue;
            //cout << i << "  " << pos2 << endl;
            rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, (ns * 10 + i) % m , dgc ^ 1);
            rt %= mod;
        }

        rt += solve(1, 1, pos - 1, 0, 1);
        rt %= mod;
    }

    return ret = rt % mod;
}

ll calc(string &n)

{
    num = n;
    if(num == "0")
        return 0;

    return solve(1, 0, num.size(), 0, 1) - 1;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));

    cin >> m >> d;

    string l, r, l2 = "";
    cin >> l >> r;

    ll ans = calc(r);

    reverse(l.begin(), l.end());

    ll carry = 1;
    for(ll i = 0; i < l.length(); i++) {
        ll dg = l[i] - '0';
        ll res = dg - carry;
        if(res < 0) {
            carry = 1;
            res = (res + 10) % 10;
        }
        else
            carry = 0;

        l2 += (res + '0');
    }

    ll indx = l2.length() - 1;
    while(l2[indx] == '0') {
        l2.pop_back();
        indx--;
    }

    reverse(l2.begin(), l2.end());

    if(l2.length() != 0)
        ans -= calc(l2);

    cout << (ans + mod) % mod << endl;

    return 0;
}