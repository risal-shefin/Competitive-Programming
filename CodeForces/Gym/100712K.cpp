#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[100009];

int main()

{
    ll t, n;
    cin >> t;
    while(t--) {
        ll n, k, in, mn = 1e18, pos;
        scanf("%lld %lld", &n, &k);

        for(ll i = 0; i < n; i++) {
            scanf("%lld", &ara[i]);
        }

        sort(ara, ara + n);
        for(ll i = 0; i < n; i++) {
            if(ara[i] == 0)
                continue;
            if(k % ara[i] == 0) {
                pos = lower_bound(ara, ara + n, k / ara[i]) - ara;
                if(ara[pos] == (k / ara[i]) && pos != i) {
                    mn = min(mn, ara[i]);
                }
            }
        }

        if(mn == 1e18)
            printf("-1\n");
        else
            printf("%lld %lld\n", mn, k / mn);
    }
    return 0;
}