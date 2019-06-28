#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll odd[3000009], even[3000009];
ll ara[300009];
int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }
    ll xr = 0, ans = 0;
    for(ll i = 1; i <= n; i++) {
        xr ^= ara[i];
        if(i % 2 == 0) {
            ans += even[xr];
            even[xr]++;
            //cout << i << " " << even[xr] - 1 << endl;
            if(xr == 0)
                ans++;
        }
        else {
            ans += odd[xr];
            odd[xr]++;
        }
    }
    cout << ans << endl;
    return 0;
}
