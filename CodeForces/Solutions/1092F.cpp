#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll a[200009], start[200009], stop[200009], sum = 0, TM = 0, tot = 0;
ll ara[200009], tree[800009], nodeOf[200009], ans = 0, ansOfNode[200009];

vector <ll> g[200009];

void dfs(ll u, ll p, ll lv)

{
    start[u] = ++TM;
    nodeOf[TM] = u;
    sum += lv * a[u];

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        dfs(nd, u, lv + 1);
    }
    stop[u] = TM;
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = a[nodeOf[lo]];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return p1 + p2;
}

void dfs2(ll u, ll p)

{
    if(u == 1) {
        ans = max(ans, sum);
        ansOfNode[u] = sum;
    }
    else {
        ll sub = query(1, TM, start[u], stop[u], 1);
        ll baire = tot - sub;
        ansOfNode[u] = ansOfNode[p] - sub + baire;
        ans = max(ans, ansOfNode[u]);
    }

    for(ll nd: g[u]) {
        if(nd != p)
            dfs2(nd, u);
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        tot += a[i];
    }

    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1, 0);
    build(1, TM, 1);
    dfs2(1, -1);

    cout << ans << endl;

    return 0;
}