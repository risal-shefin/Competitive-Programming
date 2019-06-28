#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ara[n + 5], ara2[m + 5];
    for(ll i = 0; i < n; i++)
        scanf("%I64d", &ara[i]);
    for(ll i = 0; i < m; i++)
        scanf("%I64d", &ara2[i]);
    ll mx = -1000000000000000009, tmp = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            ll tmp1 = ara[i] * ara2[j];
            if(tmp1 > mx) {
                mx = tmp1;
                tmp = i;
            }
        }
    }
    mx = -1000000000000000009;
    for(ll i = 0; i < n; i++) {
        if(tmp == i)
            continue;
        for(ll j = 0; j < m; j++) {
            mx = max(mx, ara[i] * ara2[j]);
        }
    }
    cout << mx << endl;
    return 0;
}
