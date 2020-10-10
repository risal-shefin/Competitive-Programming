#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
#define LN 17
const ll MAX = 1e5;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, depth[MAX + 9], dis[MAX + 9], pa[LN][MAX + 9];

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

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}

void depthdfs(ll u, ll p)

{
    pa[0][u] = p;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        depth[nd] = depth[u] + 1;
        depthdfs(nd, u);
    }
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

ll dist(ll x, ll y)

{
    ll d= depth[x] + depth[y] - 2 * depth[LCA(x, y)];
    return d;
}

void update(ll nd)

{
    ll u = nd;
    while(1) {
        dis[u] = min(dis[u], dist(u, nd));
        if(u == par[u])
            break;
        u = par[u];
    }
}

ll query(ll nd)

{
    ll ret = 1e18;
    ll u = nd;
    while(1) {
        ret = min(ret, dis[u] + dist(nd, u));
        if(u == par[u])
            break;
        u = par[u];
    }

    return ret;
}

int main()

{
    for(ll i = 0; i <= MAX; i++) {
        dis[i] = 1e18;

        for(ll j = 0; j < LN; j++)
            pa[j][i] = -1;
    }

    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(1, -1);
    depthdfs(1, -1);

    for(int i=1; i<LN; i++)
        for(int j=1; j<=n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];

    update(1);
    while(m--) {
        ll t, nd;
        scanf("%lld %lld", &t, &nd);
        if(t == 1)
            update(nd);
        else
            printf("%lld\n", query(nd));
    }

    return 0;
}