#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector <ll> g[200009];
ll ara[200009], tree[4 * 200009], lazy[4 * 200009], start[200009], stop[200009], tme = 1, nodeOf[200009];
char op[10];

void dfs(ll u, ll p)

{
    nodeOf[tme] = u;
    start[u] = tme++;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        dfs(nd, u);
    }
    stop[u] = tme - 1;
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    ll mid = (lo + hi) / 2;
    tree[2 * node] = (mid - lo + 1) - tree[ 2 * node];
    tree[2 * node + 1] = (hi - mid) - tree[2 * node + 1];;

    lazy[2 * node] ^= 1;
    lazy[2 * node + 1] ^= 1;

    lazy[node] = 0;
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = ara[ nodeOf[lo] ];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) prop(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] = (hi - lo + 1) - tree[node];;
        lazy[node] ^= 1;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, 2 * node);
    update(mid + 1, hi, left, right, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) prop(lo, hi, node);
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return p1 + p2;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 2; i <= n; i++) {
        ll p;
        scanf("%lld", &p);
        g[i].pb(p);
        g[p].pb(i);
    }

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    dfs(1, -1);
    tme--;

    build(1, tme, 1);

    ll q;
    cin >> q;
    while(q--) {
        //cout << q << endl;
        scanf("%s", op);
        ll u;
        scanf("%lld", &u);

        if(op[0] == 'g') {
            printf("%lld\n", query(1, tme, start[u], stop[u], 1));
        }
        else {
            update(1, tme, start[u], stop[u], 1);
        }

    }

    return 0;
}