#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a, ll n)

{
    ll ans = 1;
    for(ll i = 1; i <= n; i++) {
        ans *= a;
        //cout << a << endl;
    }

    return ans;
}

int main()

{

    ll n, m, ans;
    cin >> n >> m;
    if(n < 64) {
        ll p = power(2, n);
        ans = m % p;
    }

    else {
        ans = m;
    }

    cout << ans << endl;

    return 0;
}