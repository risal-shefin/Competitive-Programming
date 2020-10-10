#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100009];

int main()

{
    ll n, sum = 0;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        sum += ara[i];
    }

    ll mn = 1e18, mni;
    for(ll i = 1; i <= n; i++) {
        if(ara[i] < mn) {
            mn = ara[i];
            mni = i;
        }
    }

    ll mn2 = 1e18, mni2;
    for(ll i = 1; i <= n; i++) {
        if(ara[i] < mn2 && i != mni) {
            mn2 = ara[i];
            mni2 = i;
        }
    }

    ll ans = 1e18;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= ara[i]; j++) {
            if(ara[i] % j != 0)
                continue;

            ll nw = (ara[i] / j), incr, nsum;
            if(i != mni) {
                incr = (mn * j);
                nsum = sum - ara[i] - mn + nw + incr;
            }
            else {
                incr = (mn2 * j);
                nsum = sum - ara[i] - mn2 + nw + incr;
            }

            ans = min(ans, nsum);

        }
    }

    cout << ans << endl;

    return 0;
}