#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, k, m, d;
    cin >> n >> k >> m >> d;
    /*ll lo = 1, hi = m, mx = -1, minx = 2e18;;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll tot = k * mid;
        ll cycle = n / tot;
        if(n % tot != 0)
            cycle++;
        if(cycle > d) {
            lo = mid + 1;
        }
        else {
            ll tmp = cycle * mid;
            mx = max(mx, tmp);
            hi = mid - 1;
            minx = min(minx, mid);
        }
    }

    //cout << mx << "  " << minx << endl;
    for(ll i = m; i >= minx; i--) {
        ll tot = k * i;
        ll cycle = n / tot;
        if(n % tot != 0)
            cycle++;
        ll tmp = cycle * i;
        mx = max(tmp, mx);
    }

    cout << mx << endl;*/

    ll mx = -1;
    for(ll i = 1; i <= d; i++) {
        if(n / k < i)
            break;
        ll cyc = (i - 1) * k + 1;
        ll x = n / cyc;

        x = min(x, m);
        ll tot = x * i;
        mx = max(mx, tot);

        cyc = i * k;
        x = n / cyc;

        x = min(x, m);
        tot = x * i;
        mx = max(mx, tot);
    }

    printf("%lld\n", mx);

    return 0;
}