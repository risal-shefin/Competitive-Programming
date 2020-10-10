#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll u, v, c;
};

vector <node> g;
vector <ll> tree[200009];

vector <pair <ll, ll>> inp;

ll cnt[200009];

bool cmp(node a, node b)

{
    return a.c > b.c;
}

ll par[200009];

ll fnd(ll u)

{
    if(u == par[u])
        return u;
    return par[u] = fnd(par[u]);
}

int main()

{
    for(ll i = 0; i <= 200005; i++)
        par[i] = i;

    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);

        tree[u].push_back(v);
        tree[v].push_back(u);

        inp.push_back( make_pair(u, v) );

        cnt[u]++, cnt[v]++;
    }

    for(ll i = 0; i < inp.size(); i++) {
        ll u = inp[i].first;
        ll v = inp[i].second;

        g.push_back({u, v, max(cnt[u], cnt[v]) });
    }

    sort(g.begin(), g.end(), cmp);

    ll mu = g[0].u;
    ll mv = g[0].v;
    if(cnt[mu] < cnt[mv])
        swap(mu, mv);

    for(ll i = 0; i < tree[mu].size(); i++) {
        ll u = mu;
        ll v = tree[u][i];

        ll pu = fnd(u), pv = fnd(v);
        if(pu == pv)
            continue;

        par[pv] = pu;
        printf("%lld %lld\n", u, v);
    }

    for(ll i = 1; i < g.size(); i++) {
        ll u = g[i].u;
        ll v = g[i].v;

        ll pu = fnd(u), pv = fnd(v);
        if(pu == pv)
            continue;

        par[pv] = pu;
        printf("%lld %lld\n", u, v);
    }

    return 0;
}