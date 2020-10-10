#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll a, b;
    cin >> a >> b;
    if(a > b)
        swap(a, b);

    ll dif = b - a;
    if(b % a == 0 || a % dif == 0)
        cout << 0 << endl;
    else if(dif < a)
        cout << (dif - a % dif) << endl;
    else {
        ll ans = 1e18, lcm = 1e18;
        for(ll i = 1; i * i <= dif; i++) {
            ll dv = dif / i;

            if(dv >= a) {
                ll k = dv - a;
                ll lc = ( (a + k) * (b + k) ) / __gcd(a + k, b + k);
                if(lc < lcm) {
                    lcm = lc;
                    ans = k;
                }
            }
            if(i >= a) {
                ll k = i - a;
                ll lc = ( (a + k) * (b + k) ) / __gcd(a + k, b + k);
                if(lc < lcm) {
                    lcm = lc;
                    ans = k;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}