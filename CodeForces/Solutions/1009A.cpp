#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c[10009], a[10009];

int main()

{
    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }

    for(ll i = 1; i <= m; i++) {
        scanf("%lld", &a[i]);
    }

    ll ii = 1, jj = 1;

    ll cnt = 0;
    while(ii <= n && jj <= m) {
        if(a[jj] >= c[ii]) {
            jj++;
            ii++;
            cnt++;
        }
        else
            ii++;
    }

    cout << cnt << endl;

    return 0;
}