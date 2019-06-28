#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll maxnodes = 105;
ll nodes = maxnodes, src, dest;
ll dist[maxnodes], q[maxnodes], work[maxnodes];
struct Edge
{
    ll to, rev;
    ll f, cap;
};
Edge g[maxnodes][55];
ll fsz[maxnodes];
void addEdge(ll s, ll t, ll cap)
{
    Edge a = {t, fsz[t], 0, cap};
    Edge b = {s, fsz[s], 0, 0};
    g[s][ fsz[s]++ ] = a;
    g[t][ fsz[t]++ ] = b;
}
bool dinic_bfs()
{
    fill(dist, dist + nodes, -1);
      dist[src] = 0;
    ll index = 0;
    q[index++] = src;
      for (ll i = 0; i < index; i++)
    {
        ll u = q[i];
        for (ll j = 0; j < (ll) fsz[u]; j++)
        {
            Edge &e = g[u][j];
            if (dist[e.to] < 0 && e.f < e.cap)
            {
                dist[e.to] = dist[u] + 1;
                q[index++] = e.to;
            }
        }
    }
    return dist[dest] >= 0;
}
ll dinic_dfs(ll u, ll f)
{
    if (u == dest)
        return f;
      for (ll &i = work[u]; i < (ll) fsz[u]; i++)
    {
        Edge &e = g[u][i];
          if (e.cap <= e.f) continue;
          if (dist[e.to] == dist[u] + 1)
        {
            ll flow = dinic_dfs(e.to, min(f, e.cap - e.f));
            if (flow > 0)
            {
                e.f += flow;
                g[e.to][e.rev].f -= flow;
                return flow;
            }
        }
    }
    return 0;
}
ll maxFlow(ll _src, ll _dest)
{
    src = _src;
    dest = _dest;
    ll result = 0;
    while (dinic_bfs())
    {
        fill(work, work + nodes, 0);
        while (ll delta = dinic_dfs(src, INT_MAX))
            result += delta;
    }
    return result;
}
    // addEdge(u, v, C);    edge from u to v. Capacity is C
// maxFlow(s, t);  max flow from s to t
    char grid[30][30];
ll row[] = {1, -1, 0, 0};
ll col[] = {0, 0, 1, -1};
ll cst[55][55];
struct node {
    ll id, r, c;
    node(ll _id, ll _r, ll _c) {
        id =_id;
        r = _r;
        c = _c;
    }
    node() {}
} A[55], B[55], AA[55][55], qq[700];
ll indxa, indxb, sz[55], msk[27][27];
bool vis[27][27];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        indxa = 0, indxb = 0;
        memset(sz, 0, sizeof(sz));
          ll n, id = 0;
        scanf("%d", &n);
          for(ll i = 1; i <= n; i++)
            scanf(" %s", grid[i] + 1);
          for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                if(grid[i][j] == 'G') {
                    msk[i][j] = ++id;
                    A[indxa++] = node(id, i, j);
                }
                else if(grid[i][j] == 'H') {
                    msk[i][j] = ++id;
                    B[indxb++] = node(id, i, j);
                }
            }
        }
          ll start = 0, stop = 0;
        for(ll i = 0; i < indxa; i++) {
            memset(vis, 0, sizeof(vis));
            start = 0, stop = 0;
            qq[stop++] = node(0, A[i].r, A[i].c);
            vis[ A[i].r ][ A[i].c ] = 1;
              while(start < stop) {
                node u = qq[start++];
                  if(grid[ u.r ][u.c] == 'H')
                    AA[i][ sz[i]++ ] =  node(2 * u.id + 2, u.r, u.c);
                  for(ll i = 0; i < 4; i++) {
                    ll r = u.r + row[i];
                    ll c = u.c + col[i];
                      if(r < 1 || c < 1 || r > n || c > n)
                        continue;
                      if(grid[r][c] == '#')
                        continue;
                      if(vis[r][c])
                        continue;
                      vis[r][c] = 1;
                    qq[stop++] = node(u.id + 1, r, c);
                }
            }
        }
          ll lo = 1, hi = 1500, ans = -1;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
              for(ll i = 0; i < indxa; i++) {
                ll n1 = A[i].id;
                //cout << n1 << endl;
                //cout << AA[i].size() << endl;
                addEdge(0, n1, 1);
                for(ll j = 0; j < sz[i]; j++) {
                    ll n2 = msk[AA[i][j].r][AA[i][j].c];
                      if(AA[i][j].id <= mid) {
                        addEdge(n1, n2, 1);
                        //cout << n1 << "  " << n2 << endl;
                    }
                }
            }
              for(ll i = 0; i < indxb; i++)
                addEdge(B[i].id, id + 1, 1);
              ll bp = maxFlow(0, id + 1);
            //cout << bp << "  " << B.size() << " " << mid <<endl;
            if(bp == indxb) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
              for(ll i = 0; i < maxnodes; i++)
                fsz[i] = 0;
        }
          if(ans == -1)
            printf("Case %d: Vuter Dol Kupokat\n", ++caseno);
        else
            printf("Case %d: %d\n", ++caseno, ans);
          for(ll i = 0; i < maxnodes; i++)
            fsz[i] = 0;
    }
      return 0;
}
 
