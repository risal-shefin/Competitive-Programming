#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll u, v;
};

vector <node> g, ans;
vector <ll> tree, lagbe;

ll par[200009], par2[200009];

ll fnd(ll u)

{
    if(u == par[u])
        return u;
    return par[u] = fnd(par[u]);
}

ll fnd2(ll u)

{
    if(u == par2[u])
        return u;

    return par2[u] = fnd2(par2[u]);
}

int main()

{
    for(ll i = 0; i <= 200005; i++) {
        par[i] = i;
        par2[i] = i;
    }

    ll n, m, d;
    cin >> n >> m >> d;
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);

        if(u == 1)
            tree.push_back(v);
        else if(v == 1)
            tree.push_back(u);

        g.push_back({u, v});
    }

    for(ll i = 0; i < g.size(); i++) {
        ll u = g[i].u;
        ll v = g[i].v;

        if(u == 1 || v == 1)
            continue;

        ll pu = fnd(u), pv = fnd(v);
        if(pu == pv)
            continue;

        par[pv] = pu;
    }

    ll counter = 0;
    for(ll i = 0; i < tree.size(); i++) {
        ll u = 1;
        ll v = tree[i];

        ll pv = fnd(v);
        if(pv == u)
            lagbe.push_back(v);
        else {
            ans.push_back({1, v});
            par[pv] = u;
            par2[v] = u;
        }
    }

    if(ans.size() > d || tree.size() < d) {
        cout << "NO" << endl;
        return 0;
    }

    ll rem = d - ans.size();
    for(ll i = 0; i < rem; i++) {
        par2[ lagbe[i]] = 1;
        ans.push_back({1, lagbe[i]});
    }


    for(ll i = 0; i < g.size(); i++) {
        ll u = g[i].u;
        ll v = g[i].v;

        if(u == 1 || v == 1)
            continue;

        ll pu = fnd2(u), pv = fnd2(v);
        if(pu == pv)
            continue;

        par2[pv] = pu;
        ans.push_back({u, v});
    }

    cout << "YES" << endl;
    for(node u: ans) {
        printf("%lld %lld\n", u.u, u.v);
    }

    return 0;
}