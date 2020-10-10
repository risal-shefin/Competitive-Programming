#include <bits/stdc++.h>
using namespace std;

#define ll long long
set <ll> node, root;
ll par[1009], sz[1009], ed[1009], city[1009];
bool mark[1009];

ll findr(ll u)

{
    if(par[u] == u)
        return u;
    return par[u] = findr(par[u]);
}

int main()

{
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll i = 1; i <= k; i++) {
        ll in;
        scanf("%lld", &in);
        city[i] = in;
        mark[in] = 1;
    }

    for(ll i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        ed[i] = 0;
    }

    ll ans = 0, mx = -1, mxr = 1;
    for(ll i = 1; i <= m; i++) {
        ll u , v;
        scanf("%lld %lld", &u, &v);

        ll pu = findr(u);
        ll pv = findr(v);

        if(pu == pv)
            ed[pu]++;
        else {
            par[pv] = pu;
            sz[pu] += sz[pv];
            ed[pu] += ed[pv] + 1;

            if(sz[pu] > mx) {
                mx = sz[pu];
                mxr = pu;
            }
        }

        node.insert(u);
        node.insert(v);

        if(mark[u])
            root.insert(u);
        if(mark[v])
            root.insert(v);
    }

    if(root.size() == 0 && mxr != 0) {
        par[ city[1] ] = mxr;
        sz[mxr]++;
        node.insert(city[1]);
        root.insert(city[1]);
    }

    ll unused = n - node.size() - (k - root.size());

    ll tmpe = 0, tmpn = 0;
    for(ll i = 1; i <= k; i++) {
        ll u = findr( city[i] );
        if(ed[u] == 0)
            continue;

        tmpe += ed[u];
        tmpn += sz[u];
    }

    ll tot = sz[mxr] + unused + (node.size() - tmpn);
    ans += (tot * (tot - 1)) / 2 - ed[mxr] - (m - tmpe);

    //cout << mxr << "  " << ans << "  " << tot << " " << sz[mxr] << "  " << tmpn << " " << unused << endl;

    for(ll i = 1; i <= k; i++) {
        ll u = findr(city[i]);
        if(mxr == u)
            continue;

        ans += (sz[u] * (sz[u] - 1)) / 2 - ed[u];
    }

    cout << ans << endl;

    return 0;
}