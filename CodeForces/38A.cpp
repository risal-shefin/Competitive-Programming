#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2e18
int main()
{
    ll n;
    cin >> n;
    ll d[n + 5];
    for(ll i = 2; i <= n; i++)
        cin >> d[i];
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for(ll i = a + 1; i <= b; i++) {
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}
