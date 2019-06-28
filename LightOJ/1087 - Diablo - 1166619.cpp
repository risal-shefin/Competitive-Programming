#include <bits/stdc++.h>
using namespace std;
int ara[160009], tree[500009];
#define siz 160000
void update(int lo, int hi, int left, int right, int val, int node)
{
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node] += val;
        return;
    }
      int mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);
}
int query(int lo, int hi, int indx, int carry, int node)
{
    if(lo > indx || hi < indx)
        return 0;
    if(lo == indx && hi == indx)
        return tree[node] + carry;
      int mid = (lo + hi) / 2;
    int p1 = query(lo, mid, indx, carry + tree[node], 2 * node);
    int p2 = query(mid + 1, hi, indx, carry + tree[node], 2 * node + 1);
      return max(p1, p2);
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q;
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &ara[i]);
          int indx = n, counter = n;
        printf("Case %d:\n", ++caseno);
        for(int i = 1; i <= q; i++) {
            char ch;
            int id;
            scanf(" %c %d", &ch, &id);
              if(ch == 'a') {
                ara[++indx] = id;
                counter++;
            }
              else {
                if(id > counter) {
                    printf("none\n");
                    continue;
                }
                  int add = query(1, siz, id, 0, 1);
                int tmp = id + add;
                int add2 = query(1, siz, tmp, 0, 1);
                int dif = add2 - add;
                if(dif == 0) {
                    add = tmp;
                }
                else {
                    while(dif != 0) {
                        tmp += dif;
                        int tmpadd = add2;
                        add2 = query(1, siz, tmp, 0, 1);
                        dif = add2 - tmpadd;
                          if(dif == 0) {
                            add = tmp;
                            break;
                        }
                    }
                }
                  printf("%d\n", ara[add]);
                update(1, siz, add, siz, 1, 1);
                counter--;
            }
        }
    }
      return 0;
}
 
