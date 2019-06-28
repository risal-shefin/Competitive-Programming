#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2e18
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 2e18;
    for(ll i = 1; i <= n; i++) {
        ll in;
        cin >> in;
        if(m % in == 0) {
            ans = min(ans, m / in);
        }
    }
    cout << ans << endl;
    return 0;
}
