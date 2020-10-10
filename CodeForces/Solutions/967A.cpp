#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, s, ara[105];;
    cin >> n >> s;
    for(ll i = 1; i <= n; i++) {
        ll h, m;
        cin >> h >> m;
        ll tot = h * 60 + m;
        ara[i] = tot;
    }

    if(n == 1) {
        if(ara[1] >= s + 1) {
            printf("0 0\n");
            return 0;
        }
        else {
            ll ans = ara[1] + 1 + s;
            ll m = ans % 60;
            ll h = ans / 60;
            printf("%lld %lld\n", h, m);
            return 0;
        }
    }

    if(ara[1] >= s + 1) {
        printf("0 0\n");
        return 0;
    }

    ll ans = -1;
    for(ll i = 1; i <= n; i++) {
        if(i == n) {
            ans = ara[i] + 1 + s;
            break;
        }
        ll tmp = ara[i] + 1 + s;
        if(tmp + 1 + s <= ara[i + 1]) {
            ans = tmp;
            break;
        }
    }

    ll m = ans % 60;
    ll h = ans / 60;
    printf("%lld %lld\n", h, m);

    return 0;
}