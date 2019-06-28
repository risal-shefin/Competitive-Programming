#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[10009];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        multiset <ll> num;
        ll n;
        scanf("%lld", &n);
          for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);
            num.insert(ara[i]);
        }
          bool check = 1;
        for(ll i = 1; i <= n; i++) {
            ll bef = i - 1;
            ll aft = n - i;
            if(num.find(bef) != num.end()) {
                num.erase( num.find(bef) );
            }
            else if(num.find(aft) != num.end()) {
                num.erase( num.find(aft) );
            }
            else {
                check = 0;
                break;
            }
        }
          if(!check)
            printf("Case %lld: no\n", ++caseno);
        else
            printf("Case %lld: yes\n", ++caseno);
    }
      return 0;
}
 
