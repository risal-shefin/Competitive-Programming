#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, m, k;
    cin >> n >> m >> k;
    ll ara[n + 5];
    for(ll i = 1; i <= n; i++)
        cin >> ara[i];

    ll ans = 1e18;
    for(ll i = m + 1; i <= n; i++) {
        if(!ara[i])
            continue;

        if(ara[i] <= k) {
            ans = min( ans, abs(m - i) * 10 );
            break;
        }
    }

    for(ll i = m - 1; i >= 1; i--) {
        if(!ara[i])
            continue;
        if(ara[i] <= k) {
            ans = min( ans, abs(m - i) * 10 );
            break;
        }
    }

    if(ans == 1e18)
        ans = 0;

    cout << ans << endl;
    return 0;
}