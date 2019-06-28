#include <bits/stdc++.h>
using namespace std;
#define ll int
const int mx = 1429440;
ll ans[100009], tree[4 * mx];
void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = (lo & 1);
        return;
    }
      ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(ll lo, ll hi, ll indx, ll node)
{
    if(lo > indx || hi < indx)
        return;
      if(lo == hi) {
        tree[node] = 0;
        return;
    }
      ll mid = (lo + hi) / 2;
    update(lo, mid, indx, 2 * node);
    update(mid + 1, hi, indx, 2 * node + 1);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
}
ll query(ll lo, ll hi, ll sum, ll node)
{
    if(lo == hi)
        return lo;
      ll mid = (lo + hi) / 2;
    if(tree[2 * node] >= sum)
        return query(lo, mid, sum, 2 * node);
    else
        return query(mid + 1, hi, sum - tree[2 * node], 2 * node + 1);
}
int main()
{
    build(1, mx, 1);
      ans[1] = 1;
    ans[2] = 3;
      ll cut = 3;
    for(ll i = 3; i <= 100000; i++) {
        ll mns = 0, nowi;
        for(ll j = cut; j <= mx; j += cut) {
            nowi = query(1, mx, j - mns, 1);
            update(1, mx, nowi, 1);
            mns++;
        }
          ans[i] = query(1, mx, i, 1);
        cut = ans[i];
    }
      ll t, cs = 0, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++cs, ans[n]);
    }
      return 0;
}
 
