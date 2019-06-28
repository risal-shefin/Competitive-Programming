#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[300009], lazy[300009], n;
void lazyprop(ll lo, ll hi, ll node)
{
    if(lo != hi) {
        lazy[2 * node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
      tree[node] = lazy[node] * (hi - lo + 1);
    lazy[node] = -1;
    return;
}
void update(ll lo, ll hi, ll left, ll right, ll val, ll node)
{
    if(lazy[node] != -1) lazyprop(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] = val * (hi - lo + 1);
        if(lo != hi) {
            lazy[2 * node] = val;
            lazy[2 * node + 1] = val;
        }
        return;
    }
      ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
ll query(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lazy[node] != -1) lazyprop(lo, hi, node);
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        return tree[node];
    }
      ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);
    return p1 + p2;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
      while(t--) {
        memset(tree, 0, sizeof(tree));
        memset(lazy, -1, sizeof(lazy));
          scanf("%lld", &n);
        ll q;
        scanf("%lld", &q);
        printf("Case %lld:\n", ++caseno);
        while(q--) {
            ll state;
            scanf("%lld", &state);
            if(state == 1) {
                ll i, j, v;
                scanf("%lld %lld %lld", &i, &j, &v);
                update(0, n - 1, i, j, v, 1);
            }
            if(state == 2) {
                ll i, j;
                scanf("%lld %lld", &i, &j);
                ll ans = query(0, n - 1, i , j, 1);
                ll range = j - i + 1;
                ll gcd = __gcd(ans, range);
                ans = ans / gcd;
                range = range / gcd;
                if(range == 1) {
                    printf("%lld\n", ans);
                }
                else {
                    printf("%lld/%lld\n", ans, range);
                }
            }
        }
      }
      return 0;
}
 
