#include <bits/stdc++.h>
using namespace std;

#define ll long long

bitset <100009> posSum;
ll cumsum[100009];

int main()

{
    ll n, q;
    cin >> n >> q;

    posSum[0] = 1;
    for(ll i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);
        posSum |= (posSum << in);
    }

    for(ll i = 1; i <= 100000; i++)
        cumsum[i] = posSum[i] + cumsum[i - 1];

    for(ll i = 1; i <= q; i++) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", cumsum[r] - cumsum[l - 1]);
    }

    return 0;
}
