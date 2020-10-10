#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, m, cnt = 0;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            if( !(a == 0 && b == 0) ) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}