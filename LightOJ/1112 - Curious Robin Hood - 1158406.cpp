#include <bits/stdc++.h>
using namespace std;
int ara[100009], tree[400009];
int init(int l, int r, int node)
{
    if(l == r)
         return tree[node] = ara[l];
       int mid = (l + r) / 2;
     int left = init(l, mid, 2 * node);
     int right = init(mid + 1, r, 2 * node + 1);
       return tree[node] = left + right;
}
void update(int l, int r, int indx, int val,  int node)
{
    if(indx < l || indx > r)
        return;
    if(l == r) {
        tree[node] += val;
        return;
    }
      int mid = (l + r) /  2;
    update(l, mid, indx, val, 2 * node);
    update(mid + 1, r, indx, val, 2 * node + 1);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int lo, int hi, int l, int r, int node)
{
    if(lo > r || hi < l)
          return 0;
     if(lo >= l && hi <= r)
           return tree[node];
        int mid = (lo + hi) / 2;
     int left = query(lo, mid, l, r, 2 * node);
     int right = query(mid + 1, hi, l, r, 2 * node + 1);
       return left + right;
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
          for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
        }
          init(0, n - 1, 1);
        printf("Case %d:\n", ++caseno);
        for(int i = 1; i <= q; i++) {
            int op;
            scanf("%d", &op);
            if(op == 1) {
                int indx;
                scanf("%d", &indx);
                int ans = query(0, n - 1, indx, indx, 1);
                printf("%d\n", ans);
                //update(0, n - 1, indx, -ara[indx], 1);
                update(0, n - 1, indx, -ans, 1);
            }
            if(op == 2) {
                int indx, val;
                scanf("%d %d", &indx, &val);
                update(0, n - 1, indx, val, 1);
            }
              if(op == 3) {
                /*for(int i = 1; i <= 9; i++)
                    printf("%d\t", tree[i]);
                cout << endl;*/
                int i, j;
                scanf("%d %d", &i, &j);
                int ans = query(0, n - 1, i, j, 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
 
