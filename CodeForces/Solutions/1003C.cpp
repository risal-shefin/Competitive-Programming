#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[5009];

int main()

{
    double ans = -1e18;
    ll n, k;
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i <= n; i++) {
        ll cnt = 0, sum = 0;
        for(ll j = i; j <= n; j++) {
            cnt++;
            sum += ara[j];
            if(cnt >= k) {
                double tmp = (sum * 1.0) / cnt;
                ans = max(ans, tmp);
            }
        }
    }

    printf("%0.15f\n", ans);
    return 0;
}