#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll comb(ll n, ll r)

{
    if(n < r) return 0;
    ll ans = 1;
    r = min(r, n - r);
    for(ll i = 1; i <= r; i++) {
        ans = (ans * (n - i + 1) ) / i;
    }

    return ans;
}

int main()

{
    ll n, m, t, ans = 0;
    cin >> n >> m >> t;

    for(ll i = 4; i < t; i++) {
        ll girl = t - i;
        ans += comb(n, i) * comb(m, girl);
    }

    cout << ans << endl;

    return 0;
}