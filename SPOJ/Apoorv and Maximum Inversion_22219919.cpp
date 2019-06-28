#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[2000009], ara[500009], ara2[5000009], n;
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
    if(left > right)
        return 0;
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
    ll p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        ara2[i] = ara[i];
    }
     sort(ara2 + 1, ara2 + n + 1);
     for(ll i = 1; i <= n; i++)
        ara[i] = lower_bound(ara2 + 1, ara2 + n + 1, ara[i]) - ara2;
     ll l = 1, r = 1, mx = -1, ans = 1e9, tot = 0;
    for(ll i = 1; ; i++) {
        ll start = i;
        ll stop = i + p - 1;
         if(stop > n)
            break;
         while(l < start) {
            tot -= query(1, n, 1, ara[l] - 1, 1);
            update(1, n, ara[l], -1, 1);
            l++;
        }
        while(r <= stop) {
            tot += query(1, n, ara[r] + 1, n, 1);
            update(1, n, ara[r], 1, 1);
            r++;
        }
         if(tot > mx) {
            mx = tot;
            ans = start;
        }
    }
     cout << ans << " " << mx << endl;
     return 0;
}
