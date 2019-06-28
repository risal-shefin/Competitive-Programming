#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        double base = abs(a - c);
        double th = acos( (d * d + base * base - b * b) / (2 * d * base) );
        double h = d * sin(th);
        printf("Case %lld: %0.9f\n", ++caseno, 0.5 * (a + c) * h);
    }
      return 0;
}
 
