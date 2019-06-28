#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[200009], cs[200009];
ll ara2[200009];
int main()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        cs[i] += (ara[i] + cs[i - 1]);
    }
    for(ll i = 1; i <= m; i++) {
        scanf("%lld", &ara2[i]);
        ll lo = 1, hi = n, shef = -1;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(cs[mid] >= ara2[i]) {
                hi = mid - 1;
                shef = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        printf("%lld %lld\n", shef, ara2[i] - cs[shef - 1]);
    }
    return 0;
}
