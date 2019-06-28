#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll row[55];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= n; i++) {
            ll sum = 0;
            for(ll j = 1; j <= m; j++) {
                ll in;
                scanf("%lld", &in);
                sum += in;
            }
            row[i] = sum;
        }
          ll xor2 = 0;
        for(ll i = 1; i <= n; i++) {
            xor2 ^= row[i];
        }
          if(xor2 == 0) {
            printf("Case %lld: Bob\n", ++caseno);
        }
        else
            printf("Case %lld: Alice\n", ++caseno);
    }
      return 0;
}
 
