#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[105], b[105];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        bool state  = 0;
        ll indx1 = 1, indx2 = 1;
        for(ll i = 1; i <= n + n; i++) {
            if(state)
                scanf("%lld", &b[indx1++]);
            else
                scanf("%lld", &a[indx2++]);
              state ^= 1;
        }
          ll sum = 0;
        for(ll i = 1; i <= n; i++)
            sum ^= (b[i] - a[i] - 1);
          if(sum == 0)
            printf("Case %lld: Bob\n", ++caseno);
        else
            printf("Case %lld: Alice\n", ++caseno);
    }
    return 0;
}
 
