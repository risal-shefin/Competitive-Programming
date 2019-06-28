#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100009], n;
bool pos(ll k)
{
    for(ll i = 1; i <= n; i++) {
        if(ara[i]- ara[i - 1] > k)
            return false;
        if(ara[i] - ara[i - 1] == k)
            k--;
    }
    return true;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          ll lo = 1, hi = 1e9, ans = -1;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(pos(mid)) {
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
 
