#include <bits/stdc++.h>
using namespace std;

#define ll long long
bool check[105];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        for(ll j = l; j <= r; j++) {
            check[j] = 1;
        }
    }

    ll cnt = 0;
    for(ll i = 1; i <= m; i++) {
        if(!check[i])
            cnt++;
    }

    cout << cnt << endl;
    for(ll i = 1; i <= m; i++) {
        if(!check[i])
            printf("%lld ", i);
    }

    cout << endl;
    return 0;
}