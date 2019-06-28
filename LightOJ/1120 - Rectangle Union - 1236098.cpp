#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll x, state, y1, y2, si;
} ara[60009];
ll tree1[2000009], tree2[2000009], chkindx[60009], startindx[60009];
bool cmp(node a, node b)
{
    if(a.x == b.x) {
          return a.state < b.state;
    }
    return a.x < b.x;
}
void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
         tree1[node] = min(ara[lo].y1, ara[lo].y2);
         tree2[node] = max(ara[lo].y1, ara[lo].y2);
         return;
     }
       ll mid = (lo + hi) / 2;
     build(lo, mid, 2 * node);
     build(mid + 1, hi, 2 * node + 1);
       tree1[node] = min(tree1[2 * node], tree1[2 * node + 1]);
     tree2[node] = max(tree2[2 * node], tree2[2 * node + 1]);
}
void update(ll lo, ll hi, ll i, ll node)
{
    if (lo > i || hi < i)
        return;
    if (lo == hi) {
        tree1[node] = 1e18;
        tree2[node] = -1e18;
        return;
    }
      ll mid = (lo + hi) / 2;
    update(lo, mid, i, 2 * node);
    update(mid + 1, hi, i, 2 * node + 1);
      tree1[node] = min(tree1[2 * node], tree1[2 * node + 1]);
    tree2[node] = max(tree2[2 * node], tree2[2 * node + 1]);
}
ll querymn(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return 1e18;
    if(lo >= left && hi <= right)
        return tree1[node];
      ll mid = (lo + hi) / 2;
    ll p1 = querymn(lo, mid, left, right, 2 * node);
    ll p2 = querymn(mid + 1, hi, left, right, 2 * node + 1);
      return min(p1, p2);
}
ll querymx(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return -1e18;
    if(lo >= left && hi <= right)
        return tree2[node];
      ll mid = (lo + hi) / 2;
    ll p1 = querymx(lo, mid, left, right, 2 * node);
    ll p2 = querymx(mid + 1, hi, left, right, 2 * node + 1);
      return max(p1, p2);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, mxy, mny;
        scanf("%lld", &n);
        ll indx = 1;
        for(ll i = 1; i <= n; i++) {
            ll x1, x2, y1, y2;
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            ara[indx].x = x1, ara[indx].y1 = y1, ara[indx].y2 = y2, ara[indx].state = 0, ara[indx].si = indx + 1;
            indx++;
            ara[indx].x = x2, ara[indx].y1 = y1, ara[indx].y2 = y2, ara[indx].state = 1, ara[indx].si = indx;
            indx++;
        }
          sort(ara + 1, ara + indx, cmp);
        for(ll i = 1; i < indx; i++) {
            if(ara[i].state == 0)
                chkindx[ ara[i].si ] = i;
            else
                startindx[i] = chkindx[ ara[i].si ];
        }
          build(1, indx - 1, 1);
        ll ans = 0, lx, stop;
          for(ll i = 1; i < indx; i++) {
            if(i != 1 && ara[i].x != lx) {
                if(ara[i].state == 0)
                    stop = i - 1;
                else
                    stop = i;
                  ll mny = querymn(1, indx - 1, 1, stop, 1);
                ll mxy = querymx(1, indx - 1, 1, stop, 1);
                ans += (ara[i].x - lx) * (mxy - mny);
            }
              if(ara[i].state == 1) {
                update(1, indx - 1, startindx[i], 1);
                update(1, indx - 1, i, 1);
            }
              lx = ara[i].x;
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
   
