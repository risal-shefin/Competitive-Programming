#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Point {
    ll l, r;
} ara[300009];

multiset <ll> lft, rgt;

int main()

{
    ll indx = 0;
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        scanf("%lld %lld", &ara[i].l, &ara[i].r);
        lft.insert(ara[i].l);
        rgt.insert(ara[i].r);
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        lft.erase( lft.find( ara[i].l) );
        rgt.erase( rgt.find(ara[i].r) );

        ans = max(ans, *rgt.begin() - *(--lft.end() ) );

        lft.insert( ara[i].l );
        rgt.insert( ara[i].r );
    }

    cout << ans << endl;

    return 0;
}