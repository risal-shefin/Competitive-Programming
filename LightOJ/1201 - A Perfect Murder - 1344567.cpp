#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll maxnodes = 1005;
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
vector <ll> A, B, graph[maxnodes];
bool vis[maxnodes];
void dfs(ll u, bool state)
{
    vis[u] = 1;
    if(!state)
        A.push_back(u);
    else
        B.push_back(u);
      for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(vis[nd])
            continue;
          dfs(nd, state ^ 1);
    }
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%d %d", &n, &m);
          for(ll i = 1; i <= m; i++) {
            ll u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
          for(ll i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i, 0);
          for(ll i = 0; i < A.size(); i++) {
            addEdge(0, A[i], 1);
            for(ll j = 0; j < graph[ A[i] ].size(); j++)
                addEdge(A[i], graph[ A[i] ][j], 1);
        }
          for(ll j = 0; j < B.size(); j++)
            addEdge(B[j], n + 1, 1);
          ll bm = maxFlow(0, n + 1);
          printf("Case %d: %d\n", ++caseno, n - bm);
          A.clear();
        B.clear();
          for(ll i = 0; i < maxnodes; i++) {
            vis[i] = 0;
            graph[i].clear();
            g[i].clear();
        }
    }
      return 0;
}
   
