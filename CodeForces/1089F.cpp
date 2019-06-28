#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> dv;
int main()
{
    ll n, nn;
    cin >> n;
    nn = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            dv.pb(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1)
        dv.pb(n);
    if(dv.size() == 1) {
        cout << "NO" << endl;
        return 0;
    }
    n = nn;
    ll p1 = dv[0], p2 = dv[ dv.size() - 1];
    ll b = 1;
    while( (n - 1 - p2 * b) % p1 != 0)
        b++;
    ll a = (n - 1 - p2 * b) / p1;
    cout << "YES\n2" << endl;
    cout << a << " " << n / p1 << endl;
    cout << b << " " << n / p2 << endl;
    return 0;
}
