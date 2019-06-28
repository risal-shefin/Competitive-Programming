#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll dp[2][2][12][90];
vector <ll> num;
bool isPrime[100];
ll solve(ll isStart, ll isSmall, ll pos, ll sum)
 {
    if(pos == 0) {
        if(!isPrime[sum])
            return 1;
        else
            return 0;
    }
    ll &ret = dp[isStart][isSmall][pos][sum];
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
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + sum);
    }
    else {
        for(ll i = 1; i <= lim; i++)
            rt += solve(0, isSmall | i < num[pos2], pos - 1, i + sum);
         rt += solve(1, 1, pos - 1, 0);
    }
     return ret = rt;
}
ll calc(ll n)
 {
    if(n <= 1)
        return 0;
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
    isPrime[0] = 1;
    isPrime[1] = 1;
    for(ll i = 2; i <= 90; i++) {
        if(isPrime[i] == 0) {
            for(ll j = i * i; j <= 90; j += i)
                isPrime[j] = 1;
        }
    }
     memset(dp, -1, sizeof(dp));
    ll t;
    cin >> t;
    while(t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
         printf("%lld\n", calc(r) - calc(l - 1));
     }
     return 0;
