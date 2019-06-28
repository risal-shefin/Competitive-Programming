#include <bits/stdc++.h>
using namespace std;
#define sz 30009
#define tsz 60009
#define ll int
#define pb push_back
vector <ll> graph[sz];
ll node[sz], tree1[4 * tsz], tree2[4 * tsz], ltree[4 * tsz], start[sz], stop[sz], frst[sz], TM = 1;
ll nodeOf[tsz], euler_tour[tsz], el = 0;
void dfs(ll u, ll p)
{
    nodeOf[TM] = u;
    start[u] = TM++;
    frst[u] = el;
    euler_tour[ el++ ] = start[u];
    for(ll i = 0; i < graph[u].size(); i++) {
        if(graph[u][i] == p)
            continue;
        dfs(graph[u][i], u);
        euler_tour[ el++ ] = start[u];
    }
    stop[u] = TM++;
}
void update1(ll lo, ll hi, ll indx, ll val, ll node)
{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi && hi == indx) {
        tree1[node] = val;
        return;
    }
      ll mid = (lo + hi) / 2;
    update1(lo, mid, indx, val, 2 * node);
    update1(mid + 1, hi, indx, val, 2 * node + 1);
      tree1[node] = tree1[2 * node] + tree1[2 * node + 1];
}
void update2(ll lo, ll hi, ll indx, ll val, ll node)
{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi && hi == indx) {
        tree2[node] = val;
        return;
    }
      ll mid = (lo + hi) / 2;
    update2(lo, mid, indx, val, 2 * node);
    update2(mid + 1, hi, indx, val, 2 * node + 1);
      tree2[node] = tree2[2 * node] + tree2[2 * node + 1];
}
ll query1(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree1[node];
      ll mid = (lo + hi) / 2;
    ll p1 = query1(lo, mid, left, right, 2 * node);
    ll p2 = query1(mid + 1, hi, left,  right, 2 * node + 1);
      return p1 + p2;
}
ll query2(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree2[node];
      ll mid = (lo + hi) / 2;
    ll p1 = query2(lo, mid, left, right, 2 * node);
    ll p2 = query2(mid + 1, hi, left,  right, 2 * node + 1);
      return p1 + p2;
}
void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        ltree[node] = euler_tour[lo];
        return;
    }
      ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
      ltree[node] = min( ltree[2 * node], ltree[2 * node + 1] );
}
ll lcaquery(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return INT_MAX;
    if(lo >= left && hi <= right)
        return ltree[node];
      ll mid = (lo + hi) / 2;
    ll p1 = lcaquery(lo, mid, left, right, 2 * node);
    ll p2 = lcaquery(mid + 1, hi, left, right, 2 * node + 1);
      return min(p1, p2);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        el = 0, TM = 1;
        memset(tree1, 0, sizeof(tree1));
        memset(tree2, 0, sizeof(tree2));
        ll n, u, v;
        scanf("%d", &n);
        for(ll i = 0; i < n; i++)
            scanf("%d", &node[i]);
        for(ll i = 0; i < n - 1; i++) {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
          //cout << 6 << endl;
        dfs(0, -1);
        //cout << 5 << endl;;
        for(ll i = 0; i < n; i++) {
            //cout << i << "  " << start[i] << "  " << stop[i] << "  " << node[i] << endl;
            update1(1, TM, start[i], node[i], 1);
            update2(1, TM, stop[i], node[i], 1);
              //cout << query2(1, TM, stop[i], stop[i], 1) << endl;
        }
          build(0, el, 1);
          ll q;
        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);
        for(ll i = 1; i <= q; i++) {
            ll state, u, v;
            scanf("%d %d %d", &state, &u, &v);
              if(state == 0) {
                  if(u == v) {
                    printf("%d\n", node[u]);
                    continue;
                }
                  ll lca = -1;
                ll ans1 = query1(1, TM, 1, start[u], 1);
                //cout << " 1 " << ans << endl;
                ans1 -= query2(1, TM, 1, start[u], 1);
                //cout << " 2 " << ans << endl;
                  ll ans2 = query1(1, TM, 1, start[v], 1);
                //cout << " 3 " << ans2 << endl;
                ans2 -= query2(1, TM, 1, start[v], 1);
                //cout << " 4 " << ans2 << endl;
                  if(start[u] < start[v]) {
                    if(stop[u] > stop[v])
                        lca = u;
                }
                  if(start[v] < start[u]) {
                    if(stop[v] > stop[u])
                        lca = v;
                }
                  if(lca == -1) {
                    ll left = frst[u], right = frst[v];
                    if(left > right)
                        swap(left, right);
                      //cout << left  << " dgdg " << right << endl;
                    lca = nodeOf[ lcaquery(0, el, left, right, 1) ];
                }
                  ll ans3 = query1(1, TM, 1, start[ lca], 1);
                ans3 -= query2(1, TM, 1, start[ lca], 1);
                ll ans = ans1 + ans2 - (2 * ans3) + node[lca];
                printf("%d\n", ans);
            }
              else {
                node[u] = v;
                update1(1, TM, start[u], v, 1);
                update2(1, TM, stop[u], v, 1);
            }
        }
          for(ll i = 0; i < sz; i++)
            graph[i].clear();
    }
      return 0;
}
 
