#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-6
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
          ll ans = 1;
        double prob = 1;
        for(ll i = 2; i <= n; i++) {
            prob *= ((n - i + 1) / (n * 1.0));
            if(prob < 0.5) {
                ans = i - 1;
                break;
            }
        }
          printf("Case %lld: %lld\n", ++cs, ans);
    }
      return 0;
}
