#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100009];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    sort(ara + 1, ara + n + 1);

    ll mn = 0;
    for(ll i = 1; i <= m; i++) {
        ll lo = 1, hi = n, num = 0;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll tmp = max(0LL, ara[mid] - mn);
            if(tmp != 0) {
                hi = mid - 1;
                num = ara[mid] - mn;
            }
            else
                lo = mid + 1;
        }

        printf("%lld\n", num);
        mn += num;
    }

    return 0;
}