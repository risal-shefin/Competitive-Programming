#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100009], b[100009];
ll c0 = 0, c1 = 0;

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] %= 2;
        if(a[i] == 1)
            c1++;
        else
            c0++;
    }

    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
        b[i] %= 2;

        if(b[i] == 1) {
            if(c0 > 0) {
                c0--;
                ans++;
            }
        }
        else {
            if(c1 > 0) {
                c1--;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}