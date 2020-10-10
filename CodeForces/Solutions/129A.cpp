#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[109], cs[109];

int main()

{
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        cs[i] += (ara[i] + cs[i - 1]);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        if( (cs[n] - ara[i]) % 2 == 0)
            ans++;
    }

    cout << ans << endl;

    return 0;
}