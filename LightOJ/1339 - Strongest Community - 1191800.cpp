#include <bits/stdc++.h>
using namespace std;
int ara[100009], ans[50009], mx, counter[100009], cntcounter[100009];
#define block 320
struct node {
    int l, r, i;
} query[50009];
bool cmp(node a, node b)
{
    if(a.l / block != b.l / block)
        return a.l < b.l;
    return a.r < b.r;
}
void del(int indx)
{
    cntcounter[ counter[ ara[indx] ] ]--;
    counter[ ara[indx] ]--;
    cntcounter[ counter[ ara[indx] ] ]++;
      if(cntcounter[mx] == 0)
        mx--;
}
void add(int indx)
{
    cntcounter[ counter[ ara[indx] ] ]--;
    counter[ ara[indx] ]++;
    cntcounter[ counter[ ara[indx] ] ]++;
    mx = max(mx, counter[ ara[indx] ]);
}
int main()
{
    int t, caseno = 0;
    cin >> t;
    while(t--) {
        int n, c, q;
        scanf("%d %d %d", &n, &c, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &ara[i]);
          for(int i = 0; i < q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            query[i].l = l;
            query[i].r = r;
            query[i].i = i;
        }
          sort(query, query + q, cmp);
        int curl = 0, curr = 0;
        mx = 0;
        for(int i = 0; i < q; i++) {
              while(curl < query[i].l) {
                del(curl);
                curl++;
            }
              while(curl > query[i].l) {
                add(curl - 1);
                curl--;
            }
              while(curr <= query[i].r) {
                add(curr);
                curr++;
            }
              while(curr > query[i].r + 1) {
                del(curr - 1);
                curr--;
            }
              ans[ query[i].i ] = mx;
            //cout << " ere " << query[i].l << "  " << query[i].r << "  " << mx << endl;
        }
          printf("Case %d:\n", ++ caseno);
        for(int i = 0; i < q; i++) {
            printf("%d\n", ans[i]);
        }
          memset(counter, 0, sizeof(counter));
        memset(cntcounter, 0, sizeof(cntcounter));
    }
      return 0;
}
