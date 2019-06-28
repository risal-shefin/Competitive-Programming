#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point {
    ll x, y;
      point(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
      point() {}
} ara[705];
ll n;
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
          scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld %lld", &ara[i].x, &ara[i].y);
          ll mx = 1;
        for(ll i = 1; i <= n; i++) {
            ll cnt;
            for(ll j = i + 1; j <= n; j++) {
                cnt = 2;
                for(ll k = j + 1; k <= n; k++) {
                    if( (ara[j].y - ara[i].y) * (ara[k].x - ara[j].x) == (ara[k].y - ara[j].y) * (ara[j].x - ara[i].x) )
                        cnt++;
                }
                  mx = max(mx, cnt);
            }
        }
          printf("Case %lld: %lld\n", ++caseno, mx);
    }
      return 0;
}
 
