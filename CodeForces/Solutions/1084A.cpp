#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[105];

int main()

{
    ll cst = 1e18;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> ara[i];;

    for(ll i = 1; i <= n; i++) {
        ll x = i;

        ll sum = 0;
        for(ll i = 1; i <= n; i++) {
            ll tmp = abs(x - i) + abs(i - 1) + abs(x - 1);
            tmp *= 2;
            tmp *= ara[i];

            sum += tmp;
        }

        cst = min(cst, sum);

    }

    cout << cst << endl;

    return 0;
}