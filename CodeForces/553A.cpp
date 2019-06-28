#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll comb[1005][1005], ara[1005];
int main()
{
    for(ll i = 0; i < 1005; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(ll j = 1; j <= i / 2; j++) {
            comb[i][j] = comb[i][i - j] = (comb[i - 1][j] % mod + comb[i - 1][j - 1] % mod) % mod;
        }
    }
    ll n, total = 0;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> ara[i];
        total += ara[i];
    }
    ll ans = 1;
    for(ll i = n -1; i >= 1; i--) {
        ans = (ans % mod * ( comb[total - 1][ ara[i] - 1] % mod) ) % mod;
        total -= ara[i];
    }
    cout << ans << endl;
    return 0;
}
