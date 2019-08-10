#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pb push_back
#define pll pair<ll,ll>
#define x first
#define y second
#define block 320

ll num[100009];
pll pnt[50009];
vector <int> xx[100009], b[block];

ll query(ll &x1, ll &y1, ll x2, ll y2)

{

    ll b1 = x1 / block, b2 = x2 / block;
    if(b1 == b2) {
        ll ans = 0;
        for(ll i = x1; i <= x2; i++) {
            ll rng1 = lower_bound(xx[i].begin(), xx[i].end(), y1) - xx[i].begin();
            ll rng2 = upper_bound(xx[i].begin(), xx[i].end(), y2) - xx[i].begin();

            //cout << i << "  " << rng1 << " " << rng2 << endl;
            ans += (rng2 - rng1);
        }
        return ans;
    }

    ll ans = 0;
    for(ll i = x1; i < (b1 + 1) * block; i++) {
        ll rng1 = lower_bound(xx[i].begin(), xx[i].end(), y1) - xx[i].begin();
        ll rng2 = upper_bound(xx[i].begin(), xx[i].end(), y2) - xx[i].begin();

        ans += (rng2 - rng1);
    }
    for(ll i = b1+1; i < b2; i++) {
        ll rng1 = lower_bound(b[i].begin(), b[i].end(), y1) - b[i].begin();
        ll rng2 = upper_bound(b[i].begin(), b[i].end(), y2) - b[i].begin();

        ans += (rng2 - rng1);
    }
    for(ll i = b2*block; i <= x2; i++) {
        ll rng1 = lower_bound(xx[i].begin(), xx[i].end(), y1) - xx[i].begin();
        ll rng2 = upper_bound(xx[i].begin(), xx[i].end(), y2) - xx[i].begin();

        ans += (rng2 - rng1);
    }
    return ans;
}

int main()

{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll p, q, indx = 0;
        scanf("%d %d", &p, &q);

        for(ll i = 1; i <= p; i++) {
            scanf("%d %d", &pnt[i].x, &pnt[i].y);
            num[indx++] = pnt[i].x;
            num[indx++] = pnt[i].y;
        }
        sort(num, num + indx);

        for(ll i = 1; i <= p; i++) {
            pnt[i].x = lower_bound(num, num + indx, pnt[i].x) - num;
            pnt[i].y = lower_bound(num, num + indx, pnt[i].y) - num;

            xx[pnt[i].x].pb(pnt[i].y);
            b[ pnt[i].x / block].pb(pnt[i].y);
        }

        for(ll i = 0; i <= 100002; i++) sort(xx[i].begin(), xx[i].end());
        for(ll i = 0; i < block; i++) sort(b[i].begin(), b[i].end());

        printf("Case %d:\n", ++cs);
        ll x1, x2, y1, y2;
        while(q--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            ll posx1 = lower_bound(num, num + indx, x1) - num;
            ll posx2 = upper_bound(num, num + indx, x2) - num;
            if(posx2 - posx1 == 0) {
                printf("0\n");
                continue;
            }
            ll posy1 = lower_bound(num, num + indx, y1) - num;
            ll posy2 = upper_bound(num, num + indx, y2) - num;
            if(posy2 - posy1 == 0) {
                printf("0\n");
                continue;
            }
            printf("%d\n", query(posx1, posy1, posx2-1, posy2-1));
        }

        for(ll i = 0; i <= 100002; i++) xx[i].clear();
        for(ll i = 0; i < block; i++) b[i].clear();
    }

    return 0;
}
