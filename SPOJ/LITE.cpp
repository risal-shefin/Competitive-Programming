#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll tree[400009];
bool prop[400009];

void init(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = 0;
        prop[node] = 0;
        return;
    }

    ll mid = (lo + hi) / 2;
    init(lo, mid, 2 * node);
    init(mid + 1, hi, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
    prop[node] = prop[2 * node] + prop[2 * node + 1];
}

void update(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] = hi - lo + 1 - tree[node];
        prop[node] = prop[node] ^ 1;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, 2 * node);
    update(mid + 1, hi , left, right, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
    if(prop[node] == 1)
        tree[node] = hi - lo + 1 - tree[node];
}

ll query(ll lo, ll hi, ll left, ll right, bool carry, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        if(carry == 0)
            return tree[node];
        else
            return hi - lo + 1 - tree[node];
    }

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, carry ^ prop[node], 2 * node);
    ll p2 = query(mid + 1, hi, left, right, carry ^ prop[node], 2 * node + 1);

    return p1 + p2;
}

int main()

{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    init(0, n - 1, 1);

    for(ll i = 1; i <= m; i++) {
        ll state, p, q;
        scanf("%lld %lld %lld", &state, &p, &q);
        if(state == 0)
            update(0, n - 1, p - 1, q - 1, 1);
        else
            printf("%lld\n", query(0, n - 1, p - 1, q - 1, 0, 1));
    }
    return 0;
}
