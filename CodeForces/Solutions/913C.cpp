#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, L;
    cin >> n >> L;
    ll price[n + 5], lit[n + 5];

    for(ll i = 0; i < n; i++) {
        lit[i] = 1LL << i;
        cin >> price[i];
    }

    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = i - 1; j >= 0; j--) {
            ll tmp = lit[i] / lit[j];
            tmp = tmp * price[j];
            price[i] = min(tmp, price[i]);
        }
    }

    ll cost = 0, m = 1LL << 62, prc;
    for(ll i = n - 1; i >= 0; i--) {
        ll amount = L / lit[i];
        prc = amount * price[i];

        if(L % lit[i] != 0) {
            ll cst = (amount + 1) * price[i];
            m = min(cost + cst, m);
        }
        else {
            m = min(cost + prc, m);
            break;
        }

        L -= amount * lit[i];
        cost += prc;
    }
    cout << m << endl;
    return 0;
}