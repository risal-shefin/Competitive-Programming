#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define inf 1e18

struct node {
    ll state, c, t;
    node(ll _state, ll _c, ll _t) {
        state = _state;
        c = _c;
        t = _t;
    }
};

bool cmp(node a, node b)

{
    return a.c < b.c;
}

vector <node> ara;
ll ans[100009];

int main()

{
    ll n, q, last, cycle = 0;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        char ch;
        ll t, k;
        scanf(" %c %lld %lld", &ch, &t, &k);
        if(i != 1)
            ara.pb( node(1, cycle, t - last) );

        if(ch == '-')
            k = -k;

        cycle += k;
        last = t;
    }

    for(ll i = 1; i <= q; i++) {
        ll in;
        scanf("%lld", &in);
        if(in < abs(cycle) )
            ans[i] = inf;
        else
            ara.pb( node(0, -in, i) );
    }

    sort(ara.begin(), ara.end(), cmp);

    ll sum = 0, tme = 0;
    for(ll i = 0; i < ara.size(); i++) {
        if(i != 0)
            sum += (ara[i].c - ara[i - 1].c) * tme;

        if(ara[i].state == 1)
            tme += ara[i].t;
        else
            ans[ara[i].t] = sum;

    }

    for(ll i = 1; i <= q; i++) {
        if(ans[i] == inf)
            printf("INFINITY\n");
        else
            printf("%lld\n", ans[i]);
    }

    return 0;
}