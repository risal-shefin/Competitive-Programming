#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[105];

int main()

{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        ll n, mx = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++) {
            cin >> ara[i];
            mx = max(mx, ara[i]);
        }

        ll bon = 100 - mx;
        ll cnt = 0;
        for(ll i = 1; i <= n; i++) {
            if(ara[i] + bon >= 50)
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}