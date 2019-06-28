#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[2009];
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          sort(ara + 1, ara + n + 1);
          ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = i + 1; j <= n; j++) {
                ll sum = ara[i] + ara[j];
                ll pos = lower_bound(ara + 1, ara + n + 1, sum) - ara;
                  ans += max(0LL, pos - 1 - j);
            }
        }
          printf("Case %lld: %lld\n", ++cs, ans);
    }
      return 0;
}
 
