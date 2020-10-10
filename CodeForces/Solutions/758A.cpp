#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[105];

int main()

{
    ll n;
    cin >> n;
    ll mx = 0;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        mx = max(mx, ara[i]);
    }

    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        sum += (mx - ara[i]);
    }

    cout << sum << endl;

    return 0;
}