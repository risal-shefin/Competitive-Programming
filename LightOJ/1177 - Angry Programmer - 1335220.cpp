#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 105;
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
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll m, w;
        scanf("%lld %lld", &m, &w);
          for(ll i = 2; i < m; i++) {
            ll c;
            scanf("%lld", &c);
            addEdge(i, m + i, c);
        }
        addEdge(1, m + 1, INT_MAX);
        addEdge(m, m + m, INT_MAX);
          for(ll i = 1; i <= w; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
              addEdge(m + u, v, c);
            addEdge(m + v, u, c);
        }
          printf("Case %lld: %lld\n", ++caseno, maxFlow(1, m));
          for(ll i = 0; i < maxnodes; i++)
            g[i].clear();
      }
      return 0;
}
 
