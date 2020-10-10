#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pll pair <ll, ll>
ll lft[200009], rgt[200009], col[200009], num[400009];
vector <ll> start[400009], stop[400009];
set <pll> boundaryCol;

void clr()

{
    for(ll i = 0; i <= 400005; i++) {
        start[i].clear();
        stop[i].clear();
    }
    boundaryCol.clear();
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        ll indx = 1;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld", &lft[i], &rgt[i]);
            num[indx++] = lft[i];
            num[indx++] = rgt[i];
        }
        sort(num + 1, num + indx);
        ll lim = unique(num + 1, num + indx) - num;

        if(k > n) {
            printf("0\n");
            for(ll i = 1; i <= n; i++) {
                if(i != 1)
                    printf(" ");
                printf("1");
            }
            printf("\n");
            continue;
        }

        for(ll i = 1; i <= n; i++) {
            lft[i] = lower_bound(num + 1, num + lim, lft[i]) - num;
            rgt[i] = lower_bound(num + 1, num + lim, rgt[i]) - num;

            start[ lft[i] ].pb(i);
            stop[ rgt[i] ].pb(i);
        }

        for(ll i = 1; i <= k; i++)
            boundaryCol.insert(pll(0, i));

        ll intersect = 0, area = 0;
        for(ll i = 1; i < lim; i++) {
            if(i > 1 && intersect >= k)
                area += (num[i] - num[i - 1]);

            for(ll j = 0; j < start[i].size(); j++) {
                pll u = *boundaryCol.begin();
                boundaryCol.erase(u);

                col[start[i][j]] = u.second;
                intersect++;
                boundaryCol.insert(pll(rgt[start[i][j]], u.second));
            }

            for(ll j = 0; j < stop[i].size(); j++)
                intersect--;
        }

        printf("%lld\n", area);
        for(ll i = 1; i <= n; i++) {
            if(i != 1)
                printf(" ");
            printf("%lld", col[i]);
        }
        printf("\n");

        clr();

    }

    return 0;
}