#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 10005;
ll nodes = maxnodes, src, dest;
ll dist[maxnodes], q[maxnodes], work[maxnodes];
struct Edge
{
    ll to, rev;
    ll f, cap;
};
vector<Edge> g[maxnodes];
void addEdge(ll s, ll t, ll cap)
{
    Edge a = {t, g[t].size(), 0, cap};
    Edge b = {s, g[s].size(), 0, 0};
    g[s].push_back(a);
    g[t].push_back(b);
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
        for (ll j = 0; j < (ll) g[u].size(); j++)
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
      for (ll &i = work[u]; i < (ll) g[u].size(); i++)
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
map <string, ll> num;
map <bool, bool> check[maxnodes];
string siz[] = {"XS", "S", "M", "L", "XL", "XXL"};
string in1, in2;
int main()
{
    std::ios_base::sync_with_stdio(false);
      for(ll i = 0; i < 6; i++)
        num[ siz[i] ] = i;
      ll t, caseno = 0, nd;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
          nd = m;
        for(ll i = 1; i <= m; i++) {
            cin >> in1 >> in2;
            addEdge(i, ++nd, 1);
            for(ll j = 1; j <= n; j++) {
                addEdge(nd, 5100 + num[in1] * n + j, 1);
                  if(!check[5100 + num[in1] * n + j][6000 + num[in1] * n + j]) {
                    addEdge(5100 + num[in1] * n + j, 6000 + num[in1] * n + j, 1);
                    check[5100 + num[in1] * n + j][6000 + num[in1] * n + j] = 1;
                }
                  if(!check[6000 + num[in1] * n + j][10000] ) {
                    addEdge(6000 + num[in1] * n + j, 10000, 1);
                    check[6000 + num[in1] * n + j][10000] = 1;
                }
                  //cout << 6000 + num[in1] * n + j << endl;
            }
              addEdge(i, ++nd, 1);
            for(ll j = 1; j <= n; j++) {
                addEdge(nd, 5100 + num[in2] * n + j, 1);
                  if(!check[5100 + num[in2] * n + j][6000 + num[in2] * n + j]) {
                    addEdge(5100 + num[in2] * n + j, 6000 + num[in2] * n + j, 1);
                    check[5100 + num[in2] * n + j][6000 + num[in2] * n + j] = 1;
                }
                  if(!check[6000 + num[in2] * n + j][10000] ) {
                    addEdge(6000 + num[in2] * n + j, 10000, 1);
                    check[6000 + num[in2] * n + j][10000] = 1;
                }
                  //cout << 6000 + num[in2] * n + j << endl;
            }
              addEdge(0, i, 1);
        }
//        addEdge(0, 1, 1), addEdge(0, 2, 1), addEdge(0, 3, 1), addEdge(0, 4, 1);
//        addEdge(1, 6, 1), addEdge(1, 9, 1), addEdge(2, 8, 1), addEdge(2, 6, 1), addEdge(3, 8, 1), addEdge(3, 9, 1), addEdge(4, 8, 1), addEdge(4, 9, 1);
//        addEdge(6, 10, 1), addEdge(8, 11, 1), addEdge(9, 12, 1);
//        addEdge(10, 13, 1), addEdge(11, 13, 1), addEdge(12, 13, 1);
        ll fl = maxFlow(0, 10000);
        //cout << fl << endl;
        cout << "Case " << ++caseno << ": ";
        if(fl == m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
          for(ll i = 0; i < maxnodes; i++) {
            g[i].clear();
            dist[i] = 0;
            work[i] = 0;
            q[i] = 0;
            check[i].clear();
        }
      }
      return 0;
}
 
