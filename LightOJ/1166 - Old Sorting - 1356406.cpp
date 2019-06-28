#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pos[105], ara[105];
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);
            pos[ ara[i] ] = i;
        }
        ll cnt = 0;
        for(ll i = 1; i <= n; i++) {
            if(i == ara[i])
                continue;
              //cout << ara[i] << endl;
            ll tmp = pos[ i];
            swap(ara[i], ara[ tmp ]);
            pos[ ara[ tmp] ] = tmp;
            pos[i] = i;
            cnt++;
        }
          printf("Case %lld: %lld\n", ++cs, cnt);
      }
    return 0;
}
 
