#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[4000009], ara[1000009];
void build(ll lo, ll hi, ll node)
 {
    if(lo == hi) {
        tree[node] = ara[lo];
        return;
    }
     ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
     tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(ll lo, ll hi, ll indx, ll val, ll node)
 {
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        tree[node] += val;
        return;
    }
     ll mid = (lo + hi) / 2;
    update(lo, mid, indx, val, 2 * node);
    update(mid + 1, hi, indx, val, 2 * node + 1);
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
int main()
 {
    ll n, l, r;
    char ch;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);
     build(1, n, 1);
    ll q;
    cin >> q;
    while(q--) {
        scanf(" %c", &ch);
        scanf("%lld  %lld", &l, &r);
        if(ch == 'q') {
            printf("%lld\n", query(1, n, l, r, 1));
        }
        else
            update(1, n, l, r, 1);
    }
    return 0;
}
