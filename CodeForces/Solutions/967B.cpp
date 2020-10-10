#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

struct  node {
    ll sz;
    ll id;
}ara[100009];

bool cmp(node a, node b)

{
    return a.sz > b.sz;
}

int main()

{
    ll n, a, b, f, sum = 0;
    cin >> n >> a >> b;

    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i].sz);
        ara[i].id = i;
        if(i == 0) {
            f = ara[i].sz;
        }

        sum += ara[i].sz;
    }

    double tmp = (f * a * 1.0) / sum;
    if(tmp >= (b * 1.0)) {
        printf("0\n");
        return 0;
    }

    sort(ara, ara + n, cmp);

    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(ara[i].id == 0)
            continue;

        sum -= ara[i].sz;

        double am = (f * a * 1.0) / sum;
        cnt++;
        if(am >= (b * 1.0) ) {
            printf("%lld\n", cnt);
            return 0;
        }
    }

    return 0;
}