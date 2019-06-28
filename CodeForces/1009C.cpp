#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    for(ll i = 1; i <= m; i++) {
        ll x, d;
        scanf("%lld %lld", &x, &d);
        ll m = n - 1;
        ll tmp = (m * (m + 1) ) / 2;
        ll tmp2 = d * tmp;
        if(d < 0 && n > 1) {
            ll half = n / 2;
            ll left = half;
            ll right = n - half - 1;
            left = (left * (left + 1)) / 2;
            right = (right * (right + 1)) / 2;
            tmp2 = left * d + right * d;
        }
        sum += (n * x) + tmp2;
    }
    printf("%0.15f\n", (sum * 1.0) / (n * 1.0));
    return 0;
}
