#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[105], b[105];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &w[i]);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
          ll sum = 0;
        for(ll i = 1; i <= n; i++)
            sum ^= (b[i] - w[i] - 1);
          if(sum == 0)
            printf("Case %lld: black wins\n", ++caseno);
        else
            printf("Case %lld: white wins\n", ++caseno);
    }
      return 0;
}
 
