#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);
          ll sum = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                ll in;
                scanf("%lld", &in);
                  if( (i + j) % 2 != (n + m) % 2)
                    sum ^= in;
              }
        }
          if(sum == 0)
            printf("Case %lld: lose\n", ++caseno);
        else
            printf("Case %lld: win\n", ++caseno);
    }
      return 0;
}
 
