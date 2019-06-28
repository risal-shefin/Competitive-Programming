#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
pair <ll, ll> point[705];
ll ara[500005];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        set <ll> st;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld", &point[i].x, &point[i].y);
        }
          ll indx = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = i + 1; j <= n; j++) {
                ll dx = point[j].x - point[i].x;
                ll dy = point[j].y - point[i].y;
                  ara[indx++] = dx * dx + dy * dy;
            }
        }
          sort(ara, ara + indx);
        ll cnt = min(1LL, indx);
        for(ll i = 1; i < indx; i++) {
            if(ara[i] != ara[i - 1])
                cnt++;
        }
          printf("Case %lld: %lld\n", ++caseno, cnt + 1);
    }
      return 0;
}
 
