#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll t;
    ll num;
} ara[1009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld %lld", &ara[i].t, &ara[i].num);

    if(n == 1) {
        printf("%lld %lld\n", ara[1].t + ara[1].num, ara[1].num);
        return 0;
    }

    ll mx = 0, tot = 0, prt = 0;
    for(ll i = 1; i <= n; i++) {

        ll tmp = min(tot, ara[i].t - prt);
        tot -= tmp;

        prt = ara[i].t;
        tot += ara[i].num;
        mx = max(mx, tot);
        if(i == 1)
            continue;
    }

    printf("%lld %lld\n", ara[n].t + tot, mx);

    return 0;
}