#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 209;
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
ll a[105], b[105];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
          scanf("%lld", &m);
        for(ll i = 1; i <= m; i++)
            scanf("%lld", &b[i]);
          for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                if(b[j] % a[i] == 0)
                    addEdge(i, n + j, 1);
            }
        }
          for(ll i = 1; i <= n; i++)
            addEdge(0, i, 1);
          for(ll j = 1; j <= m; j++)
            addEdge(n + j, n + m + 1, 1);
          printf("Case %lld: %lld\n", ++caseno, maxFlow(0, n + m + 1));
          for(ll i = 0; i < maxnodes; i++) {
            g[i].clear();
            dist[i] = 0;
            q[i] = 0;
            work[i] = 0;
        }
      }
      return 0;
}
