#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll distp = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        ll distr = (r1 + r2) * (r1 + r2);
        ll difr = (r1 - r2) * (r1 - r2);
        if(distp >= distr) {
            printf("Case %lld: 0.0000000\n", ++caseno);
            continue;
        }
        else if(difr >= distp) {
            ll r = min(r1, r2);
            printf("Case %lld: %0.9f\n", ++caseno, pi * r * r * 1.0);
        }
        else {
            double th = acos( (r1 * r1 + distp - r2 * r2) / (2.0 * r1 * sqrt(distp) ) );
            double th2 = acos( (r2 * r2 + distp - r1 * r1) / (2.0 * r2 * sqrt(distp) ) );
            double area = 0.5 * r1 * r1 * (2 * th) - 0.5 * r1 * r1 * sin(2 * th) + 0.5 * r2 * r2 * (2 * th2) - 0.5 * r2 * r2 * sin(2 * th2);
            printf("Case %lld: %0.9f\n", ++caseno, area);
        }
      }
      return 0;
}
 
