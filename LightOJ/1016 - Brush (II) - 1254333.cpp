#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        set <ll> point;
        set <ll> :: iterator it;
        ll n, w, x, y, hi, lo, mv = 0;
        scanf("%lld %lld", &n, &w);
          for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld", &x, &y);
            point.insert(y);
        }
          while(!point.empty()) {
              it = --point.end();
            hi = *it;
            lo = hi - w;
              for(ll i = hi; i >= lo; i--) {
                it = point.find(i);
                if(it == point.end())
                    continue;
                point.erase(it);
            }
              mv++;
        }
          printf("Case %lld: %lld\n", ++caseno, mv);
    }
      return 0;
}
 
