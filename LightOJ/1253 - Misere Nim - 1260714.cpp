#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll sum = 0;
        ll n;
        scanf("%lld", &n);
          ll cnt = 0, check = 1;
        for(ll i = 1; i <= n; i++) {
            ll in;
            scanf("%lld", &in);
            sum ^= in;
            if(in > 1)
                cnt++;
            if(in != 1)
                check = 0;
        }
          printf("Case %lld: ", ++caseno);
          if(n == 1) {
            printf("Bob\n");
            continue;
        }
          if(cnt == 1) {
            printf("Alice\n");
            continue;
        }
          if(check == 1) {
            if(n % 2 != 0)
                printf("Bob\n");
            else
                printf("Alice\n");
              continue;
        }
          if(sum == 0) {
            printf("Bob\n");
        }
        else
            printf("Alice\n");
      }
      return 0;
}
 
