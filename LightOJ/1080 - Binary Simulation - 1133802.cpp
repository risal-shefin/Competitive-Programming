#include <bits/stdc++.h>
using namespace std;
char ara[100009];
int tree[400009];
void update(int b, int e, int l, int r, int node)
{
    if(b > r || e < l)
        return;
    if(b >= l && e <= r) {
        tree[node]++;
        return;
    }
      int mid = (b + e) / 2;
    update(b, mid, l, r, 2 * node);
    update(mid + 1, e, l, r, 2 * node + 1);
}
int query(int b, int e, int indx, int node)
{
    if(b > indx || e < indx)
        return 0;
    if(b == e)
        return tree[node];
      int mid = (b + e) / 2;
    int left = query(b, mid, indx, 2 * node);
    int right = query(mid + 1, e, indx, 2 * node + 1);
      return tree[node] + left + right;
}
int main()
{
    int t;
    scanf("%d", &t);
      for(int i = 1; i <= t; i++) {
        scanf("%s", ara);
        int len = strlen(ara);
          printf("Case %d:\n", i);
        int q;
        scanf("%d", &q);
        while(q--) {
            char c;
            int l, r;
            scanf(" %c", &c);
            //cout << 5 << endl;
            if(c == 'I') {
                scanf("%d %d", &l, &r);
                update(0, len, l - 1, r - 1, 1);
            }
              else {
                int indx;
                scanf("%d", &indx);
                int cnt = query(0, len, indx - 1, 1);
                  if(cnt % 2 == 1)
                    printf("%d\n", (ara[indx - 1] - 48) ^ 1);
                else
                    printf("%c\n", ara[indx - 1]);
            }
        }
          for(int j = 0; j < 400009; j++)
            tree[j] = 0;
    }
      return 0;
}
 
