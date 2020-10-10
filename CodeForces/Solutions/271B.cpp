#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> p;
bool check[200009];

ll mat[505][505], lagbe[505][505];

int main()

{
    p.push_back(2);
    for(ll i = 3; i <= 200005; i += 2) {
        if(!check[i]) {
            for(ll j = i * i; j <= 200005; j += i + i)
                check[j] = 1;

            p.push_back(i);
        }
    }

    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            scanf("%lld", &mat[i][j]);

            ll pos = lower_bound(p.begin(), p.end(), mat[i][j]) - p.begin();
            lagbe[i][j] = p[pos] - mat[i][j];
        }
    }

    ll ans = 1e18;
    for(ll i = 1; i <= n; i++) {
        ll need = 0;
        for(ll j = 1; j <= m; j++)
            need += lagbe[i][j];

        ans = min(ans, need);
    }

    for(ll i = 1; i <= m; i++) {
        ll need = 0;
        for(ll j = 1; j <= n; j++)
            need += lagbe[j][i];

        ans = min(ans, need);
    }

    cout << ans << endl;

    return 0;
}