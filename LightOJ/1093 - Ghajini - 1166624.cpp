#include <bits/stdc++.h>
using namespace std;
int n, ara[100009], tree1[300009], tree2[300009];
void init(int lo, int hi, int node)
{
    if(lo == hi) {
        tree1[node] = ara[lo];
        tree2[node] = ara[lo];
        return;
    }
      int mid = (lo + hi) / 2;
    init(lo, mid, 2 * node);
    init(mid + 1, hi, 2 * node + 1);
      tree1[node] = max(tree1[2 * node], tree1[2 * node + 1]);
    tree2[node] = min(tree2[2 * node], tree2[2 * node + 1]);
}
int query1(int lo, int hi, int left, int right, int node)
{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree1[node];
      int mid = (lo + hi) / 2;
    int p1 = query1(lo, mid, left, right, 2 * node);
    int p2 = query1(mid + 1, hi, left, right, 2 * node + 1);
      return max(p1, p2);
}
int query2(int lo, int hi, int left, int right, int node)
{
    if(lo > right || hi < left)
        return INT_MAX;
    if(lo >= left && hi <= right)
        return tree2[node];
      int mid = (lo + hi) / 2;
    int p1 = query2(lo, mid, left, right, 2 * node);
    int p2 = query2(mid + 1, hi, left, right, 2 * node + 1);
      return min(p1, p2);
}
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int d;
        scanf("%d %d", &n, &d);
        for(int i = 0; i < n; i++)
            scanf("%d", &ara[i]);
            init(0, n - 1, 1);
        int ans = INT_MIN;
        for(int i = 0; i < n - (d - 1); i++) {
            int stop = i + d - 1;
            int mx = query1(0, n - 1, i, stop, 1);
            int mn = query2(0, n - 1, i, stop, 1);
              ans = max(ans, mx - mn);
        }
          printf("Case %d: %d\n", ++caseno, ans);
    }
      return 0;
}
 
