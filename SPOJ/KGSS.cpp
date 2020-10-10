#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <ll, ll>
#define mx first
#define mx2 second

ll ara[100009];
pii tree[300009];

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node].mx = ara[lo];
        tree[node].mx2 = -1;
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node].mx = max(tree[2 * node].mx, tree[2 * node + 1].mx);
    ll tmp = max(tree[2 * node].mx2, tree[2 * node + 1].mx2);
    if(tree[2 * node].mx > tree[2 * node + 1].mx)
        tmp = max(tree[2 * node + 1].mx, tmp);
    else
        tmp = max(tree[2 * node].mx, tmp);

    tree[node].mx2 = tmp;
}

void update(ll lo, ll hi, ll i, ll val, ll node)

{
    if(lo > i || hi < i)
        return;
    if(lo == hi) {
        tree[node].mx = val;
        tree[node].mx2 = -1;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, i, val, 2 * node);
    update(mid + 1, hi, i, val, 2 * node + 1);

    tree[node].mx = max(tree[2 * node].mx, tree[2 * node + 1].mx);
    ll tmp = max(tree[2 * node].mx2, tree[2 * node + 1].mx2);
    if(tree[2 * node].mx > tree[2 * node + 1].mx)
        tmp = max(tree[2 * node + 1].mx, tmp);
    else
        tmp = max(tree[2 * node].mx, tmp);

    tree[node].mx2 = tmp;
}

pii query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return make_pair(-1e18, -1e18);
    if(lo >= left && hi <= right)
        return tree[node];

    ll mid = (lo + hi) / 2;
    pii p1 = query(lo, mid, left, right, 2 * node);
    pii p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    pii ret;
    ret.mx = max(p1.mx, p2.mx);
    ll tmp = max(p1.mx2, p2.mx2);
    if(p1.mx > p2.mx)
        tmp = max(p2.mx, tmp);
    else
        tmp = max(p1.mx, tmp);

    ret.mx2 = tmp;
    return ret;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    build(1, n, 1);
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        char ch;
        ll x, y;
        scanf(" %c %lld %lld", &ch, &x, &y);

        if(ch == 'U') {
            update(1, n, x, y, 1);
        }
        else {
            pii ans = query(1, n, x, y, 1);
            printf("%lld\n", ans.mx + ans.mx2);
        }

    }

    return 0;
}
