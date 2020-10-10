#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define eps 1e-6

struct node {
    ll b, h, w, d;
} ara[50009];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);

        ll sm = 0, mn = 1e18, mx = -1e18;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld %lld %lld", &ara[i].b, &ara[i].h, &ara[i].w, &ara[i].d);
            sm += (ara[i].h * ara[i].w * ara[i].d);
            mx = max(mx, ara[i].h + ara[i].b);
            mn = min(mn, ara[i].b);
        }

        ll v;
        scanf("%lld", &v);

        if(v > sm) {
            printf("OVERFLOW\n");
            continue;
        }

        ll cnt = 100;
        double lo = mn, hi = mx + 1, ans = -1;
        while(cnt--) {
            double mid = (lo + hi) / 2;

            double sum = 0;
            for(ll i = 1; i <= n; i++) {

                if( (double)ara[i].b - mid > eps)
                    continue;

                double h = min(mid, (double)(ara[i].b + ara[i].h) );
                h = h - ara[i].b;
                sum += (h * ara[i].w * ara[i].d);
            }

            if((double)v - sum > eps)
                lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }

        printf("%0.2f\n", ans);
    }

    return 0;
}
