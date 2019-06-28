#include <bits/stdc++.h>
using namespace std;
#define inf 2e18
#define ll long long
ll a[1009], b[1009];
struct node {
    ll i;
    ll val;
} ara[1009];
bool cmp(node a, node b) {
    return abs(a.val) > abs(b.val);
}
int main()
{
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    for(ll i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for(ll i = 0; i < n; i++)
        scanf("%lld", &b[i]);
    ll mx = INT_MIN;
    k1 += k2;
    while(k1 > 0) {
        mx = INT_MIN;
        for(ll i = 0; i < n; i++)
            mx = max(abs(a[i] - b[i]), mx);
        if(mx == 0)
            break;
        for(ll i = 0; i < n; i++) {
            if(mx == abs(a[i] - b[i] )) {
                if(a[i] > b[i]) {
                    a[i] -= min(k1, 1LL);
                }
                else {
                    b[i] -= min(k1, 1LL);
                }
                k1 -= min(k1, 1LL);
            }
        }
        /*if(test)
            break;*/
    }
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += (abs(a[i] - b[i]) * abs(a[i] - b[i]));
    }
    if(k1 < 0)
        k1 = 0;
    if(k1 % 2 != 0)
        sum++;
    cout << sum << endl;
    return 0;
}
