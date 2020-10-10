#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll a, b;
    ll dif;
} ara[100009];

bool cmp(node a, node b)

{
    return a.dif > b.dif;
}

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        ll a, b;
        scanf("%lld %lld", &ara[i].a, &ara[i].b);
        ara[i].dif = ara[i].a - ara[i].b;
    }

    sort(ara + 1, ara + n + 1, cmp);

    ll lo = 0, hi = n, ans = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        ll sum = 0;
        for(ll i = 1; i <= mid; i++)
            sum += ara[i].b;
        for(ll i = mid + 1; i <= n; i++)
            sum += ara[i].a;

        if(sum <= m) {
            hi = mid - 1;
            ans = mid;
        }
        else
            lo = mid + 1;
    }

    cout << ans << endl;

    return 0;
}