#include <bits/stdc++.h>
using namespace std;
bool tree[600009], lazy[600009];
struct {
    int l, h;
} ara[100009];
void lazypropagate(int lo, int hi, int node)
{
    if(lo != hi) {
        lazy[2 * node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
      tree[node] = 0;
    lazy[node] = 0;
}
void update(int lo, int hi, int left, int right, int node)
{
    if(lazy[node]) lazypropagate(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] = 0;
        lazy[node] = 1;
        return;
    }
      int mid = (lo + hi) / 2;
    update(lo, mid, left, right, 2 * node);
    update(mid + 1, hi, left, right, 2 * node + 1);
      tree[node] = tree[2 * node] | tree[2 * node + 1];
}
bool query(int lo, int hi, int left, int right, int node)
{
    if(lazy[node]) lazypropagate(lo, hi, node);
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        return tree[node];
    }
      int mid = (lo + hi) / 2;
    bool p1 = query(lo, mid, left, right, 2 * node);
    bool p2 = query(mid + 1, hi, left, right, 2 * node + 1);
      return p1 | p2;
}
int main()
{
      {
        int t, caseno = 0;
        cin >> t;
        while(t--) {
            memset(tree, 1, sizeof(tree));
            memset(lazy, 0, sizeof(lazy));
              int lo, hi, n;
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                int l, h;
                scanf("%d %d", &l, &h);
                ara[i].l = l;
                ara[i].h = h;
            }
              int ans = 0;
            for(int i = n - 1; i >= 0; i--) {
                ans += query(1, 2 * n, ara[i].l, ara[i].h, 1);
                //cout << ans << endl;
                update(1, 2 * n, ara[i].l, ara[i].h, 1);
            }
              printf("Case %d: %d\n", ++caseno, ans);
        }
    }
    return 0;
}
