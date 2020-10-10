#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[1000009], cs[1000009], n, ans = 1e18;

ll solve(ll k)

{
    ll cost = 0;
    for(ll i = 1; i < n; i++) {
        ll dec = cs[i] % k;
        ll inc = k - dec;
        cost += min(dec, inc);
    }

    return cost;
}

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        cs[i] = cs[i - 1] + ara[i];
    }

    if(cs[n] == 1) {
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 2; i * i <= cs[n]; i++) {
        if(cs[n] % i == 0) {
            while(cs[n] % i == 0)
                cs[n] /= i;

            ans = min(ans, solve(i));
        }
    }
    if(cs[n] > 1)
        ans = min(ans, solve(cs[n]));

    cout << ans << endl;

    return 0;
}