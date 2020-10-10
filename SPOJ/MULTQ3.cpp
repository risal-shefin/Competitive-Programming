#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll d0;
    ll d1;
    ll d2;
} tree[400009];
ll prop[400009];

void init(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node].d0 = 1;
        tree[node].d1 = 0;
        tree[node].d2 = 0;
        prop[node] = 0;
        return;
    }

    ll mid = (lo + hi) / 2;
    init(lo, mid, 2 * node);
    init(mid + 1, hi, 2 * node + 1);
    tree[node].d0 = tree[2 * node].d0 + tree[2 * node + 1].d0;
    tree[node].d1 = tree[2 * node].d1 + tree[2 * node + 1].d1;
    tree[node].d2 = tree[2 * node].d2 + tree[2 * node + 1].d2;
    prop[node] = prop[2 * node] + prop[2 * node + 1];
}

void update(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        prop[node] = (prop[node] + 1) % 3;
        int tmp0 = tree[node].d0, tmp1 = tree[node].d1, tmp2 = tree[node].d2;
        tree[node].d0 = tmp2;
        tree[node].d1 = tmp0;
        tree[node].d2 = tmp1;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, 2 * node);
    update(mid + 1, hi, left, right, 2 * node + 1);

    tree[node].d0 = tree[2 * node].d0 + tree[2 * node + 1].d0;
    tree[node].d1 = tree[2 * node].d1 + tree[2 * node + 1].d1;
    tree[node].d2 = tree[2 * node].d2 + tree[2 * node + 1].d2;

    switch(prop[node]) {
        int tmp0, tmp1, tmp2;
        case 1:
            tmp0 = tree[node].d0, tmp1 = tree[node].d1, tmp2 = tree[node].d2;
            tree[node].d0 = tmp2;
            tree[node].d1 = tmp0;
            tree[node].d2 = tmp1;
            break;
        case 2:
            tmp0 = tree[node].d0, tmp1 = tree[node].d1, tmp2 = tree[node].d2;
            tree[node].d0 = tmp1;
            tree[node].d1 = tmp2;
            tree[node].d2 = tmp0;
            break;
    }
}

ll query(ll lo, ll hi, ll left, ll right, ll carry, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        switch(carry) {
            case 0:
                return tree[node].d0;
            case 1:
                return tree[node].d2;
            case 2:
                return tree[node].d1;
        }
    }

    ll mid = (lo + hi) / 2;
    carry = (carry + prop[node]) % 3;
    ll p1 = query(lo, mid, left, right, carry, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, carry, 2 * node + 1);

    return p1 + p2;
}

int main()

{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    init(0, n - 1, 1);

    while(m--) {
        ll state, p, q;
        scanf("%lld %lld %lld", &state, &p, &q);
        if(state == 0) {
            update(0, n - 1, p, q, 1);
            //cout << 5;
        }
        else {
            printf("%lld\n", query(0, n - 1, p, q, 0, 1));
        }
    }

    return 0;
}
