#include <bits/stdc++.h>
using namespace std;

#define ll int
#define c 100009
ll ara[100009], last[c + 100009], ans[100009];

struct node {
    ll ans;
    ll cur;
} tree[300009];

struct laz {
    ll mx;
    ll cur;
} lazy[300009];

struct query {
    ll l, r, id;
} qry[100009];

bool cmp(query a, query b)

{
    return a.r < b.r;
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    lazy[2 * node].mx = max(lazy[2 * node].mx, lazy[2 * node].cur + lazy[node].mx);
    lazy[2 * node].cur += lazy[node].cur;
    tree[2 * node].ans = max(tree[2 * node].ans, tree[2 * node].cur + lazy[node].mx);
    tree[2 * node].cur += lazy[node].cur;

    lazy[2 * node + 1].mx = max(lazy[2 * node + 1].mx, lazy[2 * node + 1].cur + lazy[node].mx);
    lazy[2 * node + 1].cur += lazy[node].cur;
    tree[2 * node + 1].ans = max(tree[2 * node + 1].ans, tree[2 * node + 1].cur + lazy[node].mx);
    tree[2 * node + 1].cur += lazy[node].cur;

    lazy[node].mx = 0;
    lazy[node].cur = 0;
}

void update(ll lo, ll hi, ll left, ll right, ll val, ll node)

{
    if(lazy[node].cur || lazy[node].mx) prop(lo, hi, node);

    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node].cur += val;
        tree[node].ans = max(tree[node].ans, tree[node].cur);
        lazy[node].cur += val;
        lazy[node].mx = max(lazy[node].mx, lazy[node].cur);
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);

    tree[node].cur = max(tree[2 * node].cur, tree[2 * node + 1].cur);
    tree[node].ans = max(tree[2 * node].ans, tree[2 * node + 1].ans);
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node].cur || lazy[node].mx) prop(lo, hi, node);

    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[node].ans;

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return max(p1, p2);
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%d", &ara[i]);

    ll q;
    cin >> q;

    for(ll i = 1; i <= q; i++) {
        scanf("%d %d", &qry[i].l, &qry[i].r);
        qry[i].id = i;
    }

    sort(qry + 1, qry + q + 1, cmp);

    ll indx = 1;
    for(ll i = 1; i <= n; i++) {
        update(1, n, last[ c + ara[i] ] + 1, i, ara[i], 1);
        last[ c + ara[i] ] = i;

        while(indx <= q && qry[indx].r == i) {
            ans[ qry[indx].id ] = query(1, n, qry[indx].l, qry[indx].r, 1);
            indx++;
        }
    }

    for(ll i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
