#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100009], cs[100009];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {\
        memset(cs, 0, sizeof(cs));
        ll n, q;
        scanf("%lld %lld", &n, &q);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          sort(ara + 1, ara + n + 1);
          for(ll i = 1; i <= n; i++) {
            ll id = lower_bound(ara + 1, ara + n + 1, ara[i]) - ara;
            cs[id]++;
        }
          for(ll i = 1; i <= n; i++)
            cs[i] += cs[i - 1];
          printf("Case %lld:\n", ++caseno);
        for(ll i = 1; i <= q; i++) {
            ll l, r;
            scanf("%lld %lld", &l, &r);
            ll rgt = lower_bound(ara + 1, ara + n + 1, r) - ara;
            if(rgt > n)
                rgt--;
            else if(ara[rgt] > r)
                rgt--;
              ll lft = lower_bound(ara + 1, ara + n + 1, l) - ara;
            if(lft > n)
                lft--;
            else if(ara[lft] >= l)
                lft--;
              printf("%lld\n", cs[rgt] - cs[lft]);
        }
    }
    return 0;
}
 
