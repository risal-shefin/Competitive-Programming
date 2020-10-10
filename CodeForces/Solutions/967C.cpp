#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

ll st[100009], el[100009];

int main()

{
    ll n, m, cl, ce, v, q, x1, y1, x2, y2;
    cin >> n >> m >> cl >> ce >> v;

    for(ll i = 0; i < cl; i++) {
        scanf("%lld", &st[i]);
    }

    for(ll i = 0; i < ce; i++) {
        scanf("%lld", &el[i]);
    }

    cin >> q;
    for(ll i = 1; i <= q; i++) {
        scanf("%lld %lld %lld %lld", &y1, &x1, &y2, &x2);
        if(y1 == y2) {
            printf("%lld\n", abs(x2 - x1));
            continue;
        }

        ll ansi, dist = 2e18, dist1;
        ll tmp1 = lower_bound(st, st + cl, x1) - st - 1, tmp2 = upper_bound(st, st + cl, x1) - st;

        if(cl != 0) {
            if(tmp1 >= 0) {
                dist1 = abs(x1 - st[tmp1]) + abs(x2 - st[tmp1]) + abs(y2 - y1);
                dist = min(dist, dist1);
            }
            if(tmp2 < cl) {
                dist1 = abs(x1 - st[tmp2]) + abs(x2 - st[tmp2]) + abs(y2 - y1);
                dist = min(dist, dist1);
            }
        }

        tmp1 = lower_bound(st, st + cl, x2) - st - 1, tmp2 = upper_bound(st, st + cl, x2) - st;

        //cout << ansi << endl;
        if(cl != 0) {
            if(tmp1 >= 0) {
                dist1 = abs(x1 - st[tmp1]) + abs(x2 - st[tmp1]) + abs(y2 - y1);
                dist = min(dist, dist1);
            }
            if(tmp2 < cl) {
                dist1 = abs(x1 - st[tmp2]) + abs(x2 - st[tmp2]) + abs(y2 - y1);
                dist = min(dist, dist1);
            }
        }

        ll up = abs(y2 - y1);
        ll tme = up / v;
        if(up % v != 0)
            tme++;

        tmp1 = lower_bound(el, el + ce, x1) - el - 1, tmp2 = upper_bound(el, el + ce, x1) - el;

        //cout << ansi << endl;
        if(ce != 0) {
            if(tmp1 >= 0) {
                dist1 = abs(x1 - el[tmp1]) + abs(x2 - el[tmp1]) + tme;
                dist = min(dist, dist1);
            }
            if(tmp2 < ce) {
                dist1 = abs(x1 - el[tmp2]) + abs(x2 - el[tmp2]) + tme;
                dist = min(dist, dist1);
            }
        }

        tmp1 = lower_bound(el, el + ce, x2) - el - 1, tmp2 = upper_bound(el, el + ce, x2) - el;
        //cout << ansi << endl;

        if(ce != 0) {
            if(tmp1 >= 0) {
                dist1 = abs(x1 - el[tmp1]) + abs(x2 - el[tmp1]) + tme;
                dist = min(dist, dist1);
            }
            if(tmp2 < ce) {
                dist1 = abs(x1 - el[tmp2]) + abs(x2 - el[tmp2]) + tme;
                dist = min(dist, dist1);
            }
        }

        //cout << dist1 << "  " << dist2 << "  " << dist3 << "  " << dist4 << endl;
        ll anst = dist;

        //cout << "  " << tme << endl;
        printf("%lld\n", anst);
    }

    return 0;
}