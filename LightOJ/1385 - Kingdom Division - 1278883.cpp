/// a / d1 = b / c  --> (Triangles' base BE)
/// (a + d1) / d2 = (a + b) / (c + d1 + d2) --> (Triangle's base AB)
/// d1 = TRI XFE, d2 = TRI AFE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        if(b == 0) {
            printf("Case %lld: -1\n", ++caseno);
            continue;
        }
        else {
            double d1 = (a * c) / b;
            double ad1 = a + d1, cd1 = c + d1, ab = a + b;
            if(ab - ad1 <= 0.000000000) {
                printf("Case %lld: -1\n", ++caseno);
                continue;
            }
            double d2 = (ad1 * cd1) / (ab - ad1);
            printf("Case %lld: %0.10f\n", ++caseno, d1 + d2);
        }
    }
      return 0;
}
 
