#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <ll, ll>
#define val first
#define id second
ll posArray[100009], posTree[100009];
ll tree[300009], lazy[300009];
pii ara[100009];

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    tree[2 * node] += lazy[node];
    tree[2 * node + 1] += lazy[node];

    lazy[node] = 0;
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = ara[lo].val;
        posTree[ ara[lo].id ] = lo;
        posArray[lo] = ara[lo].id;
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(ll lo, ll hi, ll left, ll right, ll v, ll node)

{
    if(left > right)
        return;

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

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query1(ll lo, ll hi, ll pos, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > pos || hi < pos)
        return -2e18;
    if(lo == hi)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query1(lo, mid, pos, 2 * node);
    ll p2 = query1(mid + 1, hi, pos, 2 * node + 1);

    return max(p1, p2);
}

ll query2(ll lo, ll hi, ll v, ll node)

{
    if(lo == hi)
        return lo;

    if(lazy[node]) prop(lo, hi, node);

    ll mid = (lo + hi) / 2, p1 = 0, p2 = 0;

    /*if(lazy[2 * node] != 0) prop(lo, mid, 2 * node);
    if(lazy[2 * node + 1] != 0) prop(mid + 1, hi, 2 * node + 1);*/

    if(tree[2 * node] >= v)
        p1 = query2(lo, mid, v, 2 * node);
    else if(tree[2 * node + 1] >= v)
        p2 = query2(mid + 1, hi, v, 2 * node + 1);
    else
        return hi + 1;

    return max(p1, p2);
}

int main()

{
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i].val);
        ara[i].id = i;
    }

    sort(ara + 1, ara + n + 1);
    build(1, n, 1);

    for(ll i = 1; i <= q; i++) {
        ll t, x;
        scanf("%lld %lld", &t, &x);

        if(t == 1) {
            ll pos = posTree[x];

            ll v = query1(1, n, pos, 1);
            ll indx = query2(1, n, v + 1, 1) - 1;

            ll posAr = posArray[indx];

            swap(posTree[x], posTree[posAr]);
            swap(posArray[pos], posArray[indx]);

            update(1, n, indx, indx, 1, 1);
        }
        else if(t == 2) {
            ll indx = query2(1, n, x, 1);
            printf("%lld\n", n - indx + 1);
        }
        else {
            ll indx = query2(1, n, x, 1);
            update(1, n, indx, n, -1, 1);
        }

    }

    return 0;
}
