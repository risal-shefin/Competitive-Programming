// P1 = n1 / n, P2 = n2 / n
// T1 = sum(a[i]) / n1, for positive numbers
// T2= sum( abs(a[i]) ) / n2, for negative numbers
// In summary: E=P1*T1+P2*(T2+E)
// Solution: E=(P1*T1+P2*T2)/(1-P2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n, s1 = 0, s2 = 0, n2 = 0;
        scanf("%lld", &n);
          for(ll i = 1; i <= n; i++) {
            ll in;
            scanf("%lld", &in);
            if(in > 0)
                s1 += in;
            else {
                n2++;
                s2 += -in;
            }
        }
          if(s1 == 0) {
            printf("Case %lld: inf\n", ++cs);
        }
        else {
            ll nomi = s1 + s2;
            ll deno = n - n2;
            ll g = __gcd(nomi, deno);
            printf("Case %lld: %lld/%lld\n", ++cs, nomi/g, deno/g);
        }
      }
      return 0;
}
 
