#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct point {
    ll p;
    ll state;
    points(ll _p, ll _s) {
        p = _p;
        state = _s;
    }
} ara[400009];

ll cnt[400009];

bool cmp(point a, point b)

{
    if(a.p == b.p)
        return a.state > b.state;

    return a.p < b.p;
}

int main()

{
    ll n;
    cin >> n;
    ll indx = 0;
    for(ll i = 1; i <= n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        ara[indx].p = x, ara[indx].state = 1;
        indx++;
        ara[indx].p = y + 1, ara[indx].state = -1;
        indx++;
    }

    if(n == 1) {
        printf("%lld\n", ara[1].p - ara[0].p);
        return 0;
    }

    sort(ara, ara + indx, cmp);
    ll ase = 0, lx, ans = 0;
    for(ll i = 0; i < indx; i++) {

        if(i != 0) {
            //cout << ara[i].p << "  " << lx << "  " << ase << endl;
            ll counter = ara[i].p - lx;
            cnt[ase] += counter;
        }

        lx = ara[i].p;
        ase += ara[i].state;
    }

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
                printf(" ");
        printf("%lld", cnt[i]);
    }

    cout << endl;

    return 0;
}