/// “Noora” number -> if the count of distinct digits of the number is equal to the maximum digit of the number.
/// So, 123 is a Noora number but 124 is not.
/// Given n, you have to tell how many Noora number ≤ n

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll dp[2][2][21][1 << 10];
ll mcnt[1030], dist[1030];
ll num[25], indx, sz;

ll solve(ll isStart, ll isSmall, ll hi, ll mask)

{
    if(hi == 0) {
        if(mcnt[mask] != dist[mask]) {
            //cout << mask << "  " << endl;
            return 0;
        }
        else if(dist[mask] > 0)
            return 1;
        else
            return 0;
    }

    ll &ret = dp[isStart][isSmall][hi][mask];
    if(ret != -1 && isSmall)
        return ret;
    ll rt = 0, lim, pos = sz - hi;

    if(isSmall)
        lim = 9;
    else
        lim = num[pos];

    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            rt += solve(0, isSmall | i < num[pos], hi - 1, mask | (1 << i));
        }
    }
    else {
        //cout << rt << "  " << lim << endl;
        for(ll i = 1; i <= lim; i++) {
            rt += solve(0, isSmall | i < num[pos], hi - 1, mask | (1 << i));
        }

        rt += solve(1, 1, hi - 1, 0);
    }

    return ret = rt;
}

int main()

{
    memset(dp, -1, sizeof(dp));
    for(ll i = 1; i <= 1024; i++) {
        ll ct = 0, mx = 0;

        for(ll j = 0; j <= 10; j++) {
            bool state = (i >> j) & 1;
            if(state) {
                ct++;
                mx = max(mx, j);
            }
        }

        mcnt[i] = mx;
        dist[i] = ct;
    }

    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);

        indx = 0;
        while(n) {
            num[indx++] = n % 10;
            n /= 10;
        }
        reverse(num, num + indx);
        sz = indx;

        printf("%lld\n", solve(1, 0, sz, 0));
    }

    return 0;
}
