#include <bits/stdc++.h>
using namespace std;
#define ll long long
char ara[109];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    ll n;
    while(t--) {
        scanf("%lld", &n);
        scanf("%s", ara + 1);
          ll cnt = 0;
        bool ase = 0, crow = 0;
        for(ll i = 1; i <= n + 1; i++) {
              bool check = 0;
            if(ase) {
                cnt++;
                //cout << i << "  " << ara[i] << endl;
                crow = 1;
                check = 1;
            }
            if(ase)
                ase = 0;
              if(ara[i] == '.' && !crow)
                ase = 1;
              if(crow && !check)
                crow = 0;
        }
          printf("Case %lld: %lld\n", ++caseno, cnt);
    }
      return 0;
}
 
