#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pll pair <ll, ll>
#define inf (1LL << 60)

ll ara[1009];
vector <pll> ch;

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ch.clear();
        ll n, m, ans = 0, minf = inf, mins = inf, id1, id2;
        scanf("%lld %lld", &n, &m);

        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);

            if(ara[i] < minf) {
                mins = minf;
                id2 = id1;

                minf = ara[i];
                id1 = i;
            }
            else if(ara[i] < mins) {
                mins = ara[i];
                id2 = i;
            }
        }

        if(m < n || n == 2) {
            printf("-1\n");
            continue;
        }
        for(ll i = 1; i <= n; i++) {
            ans += (2 * ara[i]);

            ll nxt = (i + 1);
            if(nxt > n) nxt = 1;

            ch.pb( pll(i, nxt) );
        }

        ll lagbe = m - n;
        while(lagbe != 0) {
            ch.pb(pll(id1, id2));
            ans += mins + minf;
            lagbe--;
        }

        printf("%lld\n", ans);

        for(pll u: ch) {
            printf("%lld %lld\n", u.first, u.second);
        }
    }

    return 0;
}