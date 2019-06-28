#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
ll dp[230][230][12];
ll solve(ll start, ll tot, ll len)
 {
    ll &ret = dp[start][tot][len];
    if(ret != -1)
        return ret;
     if(len == 1)
        return ret = (start == tot);
    ll rt = 0;
    for(ll i = start; i * (len - 1) + start <= tot; i++)
        rt += solve(i, tot - start, len - 1);
     return ret = rt;
}
int main()
 {
    memset(dp, -1, sizeof(dp));
    ll t;
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld", &m, &n, &k);
         ll num = 1;
        while(1) {
            ll tmp;
            while((tmp = solve(num, m, n)) < k) {
                k -= tmp;
                num++;
            }
             m -= num;
            n--;
            printf("%lld ", num);
             if(n == 0)
                break;
        }
         printf("\n");
    }
     return 0;
}
