#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> dv[100009];

ll ase[100009];

int main()

{

    for(ll i = 1; i <= 100005; i++) {
        for(ll j = i; j <= 100005; j += i)
            dv[j].push_back(i);
    }

    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);

        ll ans = 0;
        for(ll j = 0; j < dv[x].size(); j++) {
            ll l = i - y, r = i - 1;
            if(!(ase[dv[x][j]] >= l && ase[dv[x][j]] <= r) )
                ans++;
            ase[dv[x][j]] = i;
        }

        if(y == 0) {
            printf("%lld\n", (ll)(dv[x].size()));

            continue;
        }
        else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}