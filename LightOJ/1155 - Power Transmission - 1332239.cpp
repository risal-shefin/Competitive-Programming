#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 205;
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
ll cap[maxnodes];
int main()
{
    ll t, caseno = 0;
    cin >> t;
      while(t--) {
        ll nd;
        scanf("%lld", &nd);
        for(ll i = 1; i <= nd; i++) {
            scanf("%lld", &cap[i]);
            addEdge(i, i + 101, cap[i]);
        }
          ll ed;
        scanf("%lld", &ed);
          for(ll i = 1; i <= ed; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            //c = min(c, cap[u]);
            //c = min(c, cap[v]);
              addEdge(u + 101, v, c);
            //addEdge(v, v + 101, cap[v]);
              //addEdge(v, u, c);
            //addEdge(u, u + 101, cap[u]);
        }
          ll b, d;
        scanf("%lld %lld", &b, &d);
          for(ll i = 1; i <= b; i++) {
            ll in;
            scanf("%lld", &in);
            addEdge(0, in, cap[in]);
            //addEdge(in, 0, cap[in]);
        }
          for(ll i = 1; i <= d; i++) {
            ll in;
            scanf("%lld", &in);
            //addEdge(nd + 1, in, cap[in]);
            addEdge(in + 101, 203, cap[in]);
        }
          printf("Case %lld: %lld\n", ++caseno, maxFlow(0, 203));
          for(ll i = 0; i < maxnodes; i++) {
            g[i].clear();
            dist[i] = 0;
            q[i] = 0;
            work[i] = 0;
        }
    }
      return 0;
}
 
