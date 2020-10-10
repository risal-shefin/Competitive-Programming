#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll tree[400009];
ll prop[400009];

void init(ll left, ll right, ll node)

{
    if(left == right) {
        tree[node] = 0;
        prop[node] = 0;
        return;
    }

    ll mid = (left + right) / 2;
    init(left, mid, 2 * node);
    init(mid + 1, right, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    prop[node] = prop[2 * node] + prop[2 * node + 1];
}

void update(ll lo, ll hi, ll left, ll right, ll value, ll node)

{
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] += (hi - lo + 1) * value;
        prop[node] += value;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, value, 2 * node);
    update(mid + 1, hi, left, right, value, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1] + (hi - lo + 1) * prop[node];
}

ll query(ll lo, ll hi, ll left, ll right, ll carry, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[node] + (hi - lo + 1) * carry;

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, carry + prop[node], 2 * node);
    ll p2 = query(mid + 1, hi, left, right, carry + prop[node], 2 * node + 1);

    return p1 + p2;
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n, c;
        scanf("%lld %lld", &n, &c);
        init(0, n - 1, 1);
        for(ll i = 1; i <= c; i++) {
            ll state, p, q, v;
            scanf("%lld", &state);
            if(state == 0) {
                scanf("%lld %lld %lld", &p, &q, &v);
                update(0, n - 1, p - 1, q - 1, v, 1);
            }
            else {
                scanf("%lld %lld", &p, &q);
                printf("%lld\n", query(0, n - 1, p - 1, q - 1, 0, 1));
            }
        }

    }

    return 0;
}
