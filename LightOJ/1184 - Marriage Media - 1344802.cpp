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
struct nd {
    ll h, a, d;
} ara[maxnodes];
    int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll m, n;
        scanf("%lld %lld", &m, &n);
          for(ll i = 1; i <= m; i++)
            scanf("%lld %lld %lld", &ara[i].h, &ara[i].a, &ara[i].d);
          for(ll k = m + 1, j = 1; j <= n; j++, k++) {
            scanf("%lld %lld %lld", &ara[k].h, &ara[k].a, &ara[k].d);
              addEdge(k, n + m + 1, 1);
        }
          for(ll i = 1; i <= m; i++) {
            addEdge(0, i, 1);
            for(ll k = m + 1, j = 1; j <= n; j++, k++)
                if( abs(ara[i].h - ara[k].h) <= 12 && abs(ara[i].a - ara[k].a) <= 5 && ara[i].d == ara[k].d)
                    addEdge(i, k, 1);
          }
          ll bm = maxFlow(0, n + m + 1);
          printf("Case %lld: %lld\n", ++caseno, bm);
          for(ll i = 0; i < maxnodes; i++)
            g[i].clear();
      }
      return 0;
}
 
