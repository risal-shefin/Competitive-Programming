#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
          ll lim = sqrt(n);
          ll ans = 0;
        for(ll i = 2; i <= lim; i++) {
            ans += ( (n / i - 1) * i);
        }
          ll mxOccur = n / (lim + 1);
        for(ll i = 2; i <= mxOccur; i++) {
            ll beforeStart = n / (i + 1);
            ll stop = n / i;
            ll occur = i - 1;
              ll sumOfRange = stop * (stop + 1) / 2 - beforeStart * (beforeStart + 1) / 2;
            ans += (occur * sumOfRange);
        }
          printf("Case %lld: %lld\n", ++cs, ans);
    }
      return 0;
}
 
