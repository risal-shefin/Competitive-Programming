#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n, cnt = 0;
        scanf("%lld", &n);
        ll sqt = sqrt(n);
        sqt++;
        for(ll i = 1; i <= sqt; i++) {
            if(i * i <= n)
                cnt++;
            if(2 * i * i <= n)
                cnt++;
        }
          printf("Case %lld: %lld\n", ++cs, n - cnt);
    }
      return 0;
}
 
