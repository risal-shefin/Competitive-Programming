#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
    }

    ll state = 1;
    for(ll i = 1; i <= n; i++) {
        printf("%lld", state);
        state ^= 1;
    }

    cout << endl;
    return 0;
}