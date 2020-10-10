#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll vol[1009], n, mn = 1e18;

ll fnd(ll s)

{
    ll lo = 0, hi = mn, ret = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        ll sm = 0;
        for(ll i = 1; i <= n; i++) {
            ll nibo = vol[i] - mid;
            sm += nibo;
        }

        if(sm < s)
            hi = mid - 1;
        else if(sm >= s) {
            ret = mid;
            lo = mid + 1;
        }
    }

    return ret;
}

int main()

{
    ll s;
    cin >> n >> s;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &vol[i]);
        mn = min(mn, vol[i]);
    }

    ll ans = fnd(s);

    cout << ans << endl;

    return 0;
}