#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100009], cum[100009], cum2[100009];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    ara[n + 1] = m;
    bool state = 1;
    for(ll i = 1; i <= n + 1; i++) {
        if(state) {
            cum[i] = cum[i - 1] + ara[i] - ara[i - 1];
            cum2[i] = cum2[i - 1];
        }
        else {
            cum2[i] = cum2[i - 1] + ara[i] - ara[i - 1];
            cum[i] = cum[i - 1];
        }

        state ^= 1;
    }

    ll ans = cum[n + 1];
    //cout << cum2[n + 1] << endl;

    ll ans2 = 0;
    for(ll i = 1; i <= n + 1; i++) {

        if(ara[i] - ara[i - 1] == 1)
            continue;

        if(i % 2 == 1) {
            ll tmp = ara[i] - 1;
            ans2 = cum[i - 1] + (tmp - ara[i - 1]) + cum2[n + 1] - cum2[i];
            //cout << ans << endl;
            ans = max(ans, ans2);
        }
        else {
            ll tmp = ara[i - 1] + 1;
            ans2 = cum[i - 1] + (ara[i] - tmp) + cum2[n + 1] - cum2[i];
            //cout << ans2 << "  " << i << "  " << cum[i - 1] << "  " << ara[i] - tmp << "  " << cum2[n + 1] << "  " << cum2[i - 1] << endl;
            ans = max(ans, ans2);
        }
    }

    cout << ans << endl;

    return 0;
}