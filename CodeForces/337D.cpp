#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define LN 18
const ll MAX = 1e5;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize;
ll n, m, d, af[MAX + 9];
ll depth[MAX + 9], pa[LN][MAX + 9];
ll LCA(ll u, ll v) {
	if(depth[u] < depth[v]) swap(u,v);
	ll diff = depth[u] - depth[v];
	for(ll i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(ll i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}
ll dist(ll u, ll v)
{
    ll lc = LCA(u, v);
    if(lc == u || lc == v) {
        return abs(depth[u] - depth[v]);
    }
    ll d1 = abs(depth[u] - depth[lc]);
    ll d2 = abs(depth[v] - depth[lc]);
    return d1 + d2;
}
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
ll ans = 0;
vector <ll> dt, now;
ll cnt[MAX + 9];
void adfs(ll u, ll p, ll cn)
{
    if(af[u]) {
        ll dst = dist(u, cn);
        dt.push_back(dst);
        if(dst <= d) {
            cnt[cn]++;
            //cout << " hj " << cnt[cn] << endl;
        }
    }
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        adfs(nd, u, cn);
    }
}
void adfs2(ll u, ll p, ll cn)
{
    if(af[u]) {
        ll dst = dist(u, cn);
        now.push_back(dst);
    }
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        adfs2(nd, u, cn);
    }
}
void qdfs(ll u, ll p, ll cn)
{
    ll dst = dist(u, cn);
    if(dst <= d) {
        ll need = d - dst;
        ll pos = upper_bound(dt.begin(), dt.end(), need) - dt.begin();
        pos--;
        cnt[u] += (pos + 1);
//        if(u == 5 && cn == 4) {
//        //cout << u << "  " << pos << " " << need << " " << cnt[u] << endl;
//            for(ll i = 0; i < dt.size(); i++)
//                cout << dt[i] << "  ";
//            cout << "  " << need << endl;
//        }
        pos = upper_bound(now.begin(), now.end(), need) - now.begin();
        pos--;
        cnt[u] -= (pos + 1);
        //cout << cnt[u] << endl;
    }
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        qdfs(nd, u, cn);
    }
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
        if(del[nd])
            continue;
        adfs(g[cen][i], cen, cen);
    }
    if(af[cen])
        dt.push_back(0);
    sort(dt.begin(), dt.end());
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;
        adfs2(g[cen][i], cen, cen);
        sort(now.begin(), now.end());
        qdfs(g[cen][i], cen, cen);
        now.clear();
    }
    dt.clear();
    //cout << cen << " f " << 5 << endl;
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(!del[nd])
            decompose(nd, cen);
    }
}
void ldfs(ll u, ll p, ll lv)
{
    depth[u] = lv;
    pa[0][u] = p;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;
        ldfs(nd, u, lv + 1);
    }
}
int main()
{
    cin >> n >> m >> d;
    for(ll i = 1; i <= m; i++) {
        ll inp;
        scanf("%d", &inp);
        af[inp] = 1;
    }
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    ldfs(1, -1, 0);
    for(int i=1; i<LN; i++)
        for(int j=1; j<=n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];
    decompose(1, -1);
    for(ll i = 1; i <= n; i++) {
        if(af[i])
            cnt[i]++;
        if(cnt[i] == m) {
            ans++;
           // cout << i << endl;
        }
        //cout << cnt[i] << endl;
    }
    cout << ans << endl;
    return 0;
}
