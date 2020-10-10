#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    ll u, v, c;
    edge(ll _u = 0, ll _v = 0, ll _c = 0) {
        u = _u;
        v = _v;
        c = _c;
    }
};

vector <edge> e;

bool cmp(edge a, edge b)

{
    return a.c < b.c;
}

ll par[100009], sz[100009];

ll findr(ll u)

{
    if(par[u] == u)
        return u;
    return par[u] = findr(par[u]);
}

int main()

{
    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for(ll i = 1; i <= m; i++) {
        ll u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        e.push_back( edge(u, v, c) );
    }

    sort(e.begin(), e.end(), cmp);

    for(ll i = 1; i < e.size(); i++)
        e[i].c += e[i - 1].c;

    ll ans = 0;
    for(ll i = e.size() - 1; i >= 0; i--) {
        ll u = findr(e[i].u);
        ll v = findr(e[i].v);

        if(u == v)
            continue;

        ans +=  ( (e[i].c * sz[u] * sz[v]) % 1000000000 );
        ans %= 1000000000;
        sz[u] += sz[v];
        par[v] = par[u];
    }

    cout << ans << endl;

    return 0;
}
