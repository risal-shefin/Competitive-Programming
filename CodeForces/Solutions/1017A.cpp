#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll id, sum;
} ara[10009];

bool cmp(node a, node b)

{
    if(a.sum != b.sum)
        return a.sum > b.sum;
    return a.id < b.id;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll sum = 0;
        for(ll j = 1; j <= 4; j++) {
            ll in;
            scanf("%lld", &in);
            sum += in;
        }

        ara[i].id = i;
        ara[i].sum = sum;
    }

    sort(ara + 1, ara + n + 1, cmp);
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        if(ara[i].id == 1)
            ans = i;
    }

    cout << ans << endl;

    return 0;
}