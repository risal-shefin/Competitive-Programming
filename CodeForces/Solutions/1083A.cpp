#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 3e5;
vector <ll> g[MAX + 9], cost[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, gas[MAX + 9], ans = 0;

void dfs(ll u, ll p)

{
    sz[u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        dfs(nd, u);
        sz[u] += sz[nd];
    }
}

ll findCentroid(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd] || sz[nd] <= curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}

ll trdfs(ll u, ll p, ll oil)

{
    oil += gas[u];
    ll mx = oil;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i], c = cost[u][i];
        if(del[nd] || nd == p)
            continue;

        mx = max(mx, trdfs(nd, u, oil - c));
    }

    return mx;
}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    ll mx = 0;
    ans = max(ans, gas[cen]);
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        ll ret = trdfs(nd, cen, 0);
        if(mx >= cost[cen][i])
            ans = max(ans, mx + ret - cost[cen][i]);

        mx = max(mx, ret + gas[cen] - cost[cen][i]);
        ans = max(ans, mx);
    }

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &gas[i]);
    for(ll i = 1; i < n; i++) {
        ll u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        g[u].pb(v);
        g[v].pb(u);

        cost[u].pb(c);
        cost[v].pb(c);
    }

    decompose(1, -1);

    cout << ans << endl;

    return 0;
}