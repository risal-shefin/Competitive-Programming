#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct node {
    ll a, b, c;
    node(ll _a, ll _b, ll _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};

bool operator <(node a, node b) {
    return a.c > b.c;
}
vector <node> edge;

struct quer {
    ll a, w, i;
    quer(ll _a, ll _w, ll _i) {
        a = _a;
        w = _w;
        i = _i;
    }
};

bool operator <(quer a, quer b) {
    return a.w > b.w;
}

vector <quer> qry;

ll ans[300009], par[200009], sz[200009];

ll findr(ll u)

{
    if(par[u] == u)
        return u;
    return par[u] = findr(par[u]);
}

int main()

{
    ll n, m, q;
    cin >> n >> m >> q;

    for(ll i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for(ll i = 1; i <= m; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        edge.push_back( node(a, b, c) );
    }

    sort(edge.begin(), edge.end());

    for(ll i = 1; i <= q; i++) {
        ll a, c;
        scanf("%lld %lld", &a, &c, &i);
        qry.pb( quer(a, c, i) );
    }
    sort(qry.begin(), qry.end());

    ll j = 0;
    for(ll i = 0; i < q; i++) {

        for(; j < edge.size(); j++) {
            if(edge[j].c < qry[i].w)
                break;

            ll u = findr(edge[j].a);
            ll v = findr(edge[j].b);

            if(u == v)
                continue;

            par[v] = u;
            sz[u] += sz[v];
        }

        ans[ qry[i].i ] = sz[ findr(qry[i].a) ];
    }

    for(ll i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
