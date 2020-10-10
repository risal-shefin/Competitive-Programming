#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll par[200009], mn[200009], sz[200009];

struct node {
    ll u, v, w;
} edge[100009];

bool operator <(node a, node b)

{
    return a.w < b.w;
}

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

    for(ll i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for(ll i = 1; i <= n; i++)
        scanf("%lld", &mn[i]);

    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &edge[i].u, &edge[i].v);
        edge[i].w = min(mn[ edge[i].u ], mn[ edge[i].v ] );
    }

    sort(edge + 1, edge + m + 1);

    ll ans = 0;
    for(ll i = m; i >= 1; i--) {
        ll u = findr(edge[i].u);
        ll v = findr(edge[i].v);

        if(u == v)
            continue;

        ans += (sz[u] * sz[v] * edge[i].w);
        par[v] = u;
        sz[u] += sz[v];
    }

    printf("%0.6f\n", (ans * 2.0) / ( n * (n - 1) ));

    return 0;
}