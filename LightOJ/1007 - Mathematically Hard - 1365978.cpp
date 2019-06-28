#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll pwr[5000009];
int phi[5000009];
int main()
{
    for(ll i = 1; i <= 5000000; i++)
        phi[i] = i;
      for(ll i = 2; i <= 5000000; i++) {
        if(phi[i] == i) {
            phi[i] = i - 1;
              for(ll j = 2 * i; j <= 5000000; j += i)
                phi[j] = (phi[j] / i) * (i - 1);
        }
    }
      for(ll i = 1; i <= 5000000; i++) {
        pwr[i] = (ll)phi[i] * (ll)phi[i] + pwr[i - 1];
    }
      ll t, cs = 0;
    cin >> t;
      while(t--) {
        ll a, b;
        scanf("%llu %llu", &a, &b);
          ll ans = pwr[b] - pwr[a - 1];
        printf("Case %llu: %llu\n", ++cs, ans);
    }
      return 0;
}
 
