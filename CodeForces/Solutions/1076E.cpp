#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define MAXN 300009

vector <ll> g[MAXN];
ll tree[MAXN * 4], lazy[4 * MAXN], depth[MAXN], ans[MAXN];
vector <pll> q[MAXN];

void szdfs(ll u, ll p, ll lv)

{
    depth[u] = lv;
    for(ll nd: g[u]) {
        if(nd == p)
            continue;

        szdfs(nd, u, lv + 1);
    }
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1]+= lazy[node];

    tree[2 * node] += lazy[node];
    tree[2 * node + 1] += lazy[node];

    lazy[node] = 0;
}

void update(ll lo, ll hi, ll left, ll right, ll v, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] += v;
        lazy[node] += v;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, v, 2 * node);
    update(mid + 1, hi, left, right, v, 2 * node + 1);
}

ll query(ll lo, ll hi, ll indx, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > indx || hi < indx)
        return 0;
    if(lo == hi)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, indx, 2 * node);
    ll p2 = query(mid + 1, hi, indx, 2 * node + 1);

    return p1 + p2;
}

void dfs(ll u, ll p)

{
    for(pll pr: q[u]) {
        ll l = depth[u];
        ll r = min(depth[u] + pr.first, (ll)300002);

        update(1, MAXN, l, r, pr.second, 1);
    }

    ans[u] = query(1, MAXN, depth[u], 1);

    for(ll nd: g[u]) {
        if(nd == p)
            continue;
        dfs(nd, u);
    }

    for(pll pr: q[u]) {
        ll l = depth[u];
        ll r = min(depth[u] + pr.first, (ll)300002);

        update(1, MAXN, l, r, -pr.second, 1);
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll m;
    cin >> m;
    for(ll i = 1; i <= m; i++) {
        ll v, d, x;
        scanf("%lld %lld %lld", &v, &d, &x);

        q[v].push_back( pll(d, x) );
    }

    szdfs(1, -1, 1);
    dfs(1, -1);

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;

    return 0;
}