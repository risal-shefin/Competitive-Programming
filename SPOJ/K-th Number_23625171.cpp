#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll cnt;
    node *left, *right;
     node(ll c, node *l, node *r) {
        cnt = c;
        left = l, right = r;
    }
    node() {}
     node *add(ll lo, ll hi, ll id);
};
node *null = new node(0, NULL, NULL);
node *node::add(ll lo, ll hi, ll indx)
 {
    //cout << lo <<  "  " << hi << "  " << indx << endl;
    if(lo <= indx && indx <= hi) {
        if(lo == hi)
            return new node(this -> cnt + 1, null, null);
         ll mid = (lo + hi) / 2;
         return new node(this -> cnt + 1, this -> left -> add(lo, mid, indx), this -> right -> add(mid + 1, hi, indx));
    }
     // Out of range, we can use previous tree node.
    return this;
}
ll query(node *a, node *b, ll lo, ll hi, ll k)
 {
    if(lo == hi)
        return lo;
     ll mid = (lo + hi) / 2;
    ll cnt = a -> left -> cnt - b -> left -> cnt;
    if(cnt >= k)
        return query(a -> left, b -> left, lo, mid, k);
    else
        return query(a -> right, b -> right, mid + 1, hi, k - cnt);
}
ll a[100009], a2[100009], realVal[100009];
unordered_map <ll, ll> msk;
node *root[100009];
int main()
 {
    ll n, q;
    cin >> n >> q;
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a2[i] = a[i];
    }
    sort(a2, a2 + n);
     null -> left = null ->  right = null;
    for(ll i = 0; i < n; i++) {
        msk[ a[i] ] = lower_bound(a2, a2 + n, a[i]) - a2;
        realVal[msk[a[i]]] = a[i];
        root[i] = (i == 0 ? null : root[i - 1]) -> add(0, 100000, msk[a[i]]);
    }
     for(ll i = 1; i<= q; i++) {
        ll l, r, k;
        scanf("%lld %lld %lld", &l, &r, &k);
        l--, r--;
         printf("%lld\n", realVal[query(root[r], (l == 0 ? null : root[l - 1]), 0, 100000, k)]);
    }
     return 0;
}
