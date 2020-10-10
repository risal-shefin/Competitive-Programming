#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll tree[40009], ara[10009], lazy[40009];
bool mark[1000009];

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi) return;

    ll mid = (lo + hi) / 2;
    lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
    tree[2 * node] = (mid - lo + 1) * lazy[node];
    tree[2 * node + 1] = (hi - mid) * lazy[node];

    lazy[node] = -1;
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = !mark[ ara[lo] ];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(ll lo, ll hi, ll left, ll right, ll val, ll node)

{
    if(lazy[node] != -1) prop(lo, hi, node);

    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] = (hi - lo + 1) * val;
        lazy[node] = val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node] != -1) prop(lo, hi, node);

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
    mark[1] = 1;
    for(ll i = 2; i <= 1000000; i++) {
        if(mark[i] == 0) {
            for(ll j = i * i; j <= 1000000; j += i)
                mark[j] = 1;
        }
    }

    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(lazy, -1, sizeof(lazy));
        memset(tree, 0, sizeof(tree));

        ll n, q;
        scanf("%lld %lld", &n, &q);

        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);

        build(1, n, 1);

        printf("Case %lld:\n", ++cs);
        for(ll i = 1; i <= q; i++) {
            ll type;
            scanf("%lld", &type);
            if(type == 0) {
                ll u, v, x;
                scanf("%lld %lld %lld", &u, &v, &x);
                update(1, n, u,  v, !mark[x], 1);
            }
            else {
                ll u, v;
                scanf("%lld %lld", &u, &v);
                printf("%lld\n", query(1, n, u, v, 1));
            }
        }
    }

    return 0;
