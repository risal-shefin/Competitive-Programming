#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define mp make_pair
#define pb push_back
#define pll pair <ll, ll>

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);

        ll mn = inf, mx = 0;
        for(ll i = 1; i <= n; i++) {
            ll a, b;
            scanf("%lld %lld", &a, &b);

            mn = min(mn, b);
            mx = max(mx, a);
        }

        printf("%lld\n", max(0LL, (mx - mn)));
    }
    return 0;
}