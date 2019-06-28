#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, ara[1009], m;
ll solve(ll c)
{
    ll cnt = m;
    ll indx = 1;
    ll sum = 0, rem = n;
    while(indx <= n && cnt > 0) {
          sum = 0;
        while(sum + ara[indx] <= c && rem >= cnt) {
            sum += ara[indx];
            indx++;
            rem--;
        }
        cnt--;
    }
      return (cnt == 0 & indx == n + 1);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          ll lo = 0, hi = 1e9, ans;
          while(lo <= hi) {
            ll mid = (lo + hi) / 2;
              if(solve(mid)) {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
    return 0;
}
 
