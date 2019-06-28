#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
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
struct node {
    ll t, sx, sy, ex, ey;
    node(ll _t, ll _sx, ll _sy, ll _ex, ll _ey) {
        t = _t;
        sx = _sx;
        sy = _sy;
        ex = _ex;
        ey = _ey;
    }
      node() {}
} ara[505];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
          for(ll i = 1; i <= n; i++) {
            ll hh, mm;
            scanf("%lld:%lld", &hh, &mm);
            ara[i].t = hh * 60 + mm;
            scanf("%lld %lld %lld %lld", &ara[i].sx, &ara[i].sy, &ara[i].ex, &ara[i].ey);
        }
          for(ll i = 1; i <= n; i++) {
            addEdge(0, i, 1);
            ll tme = abs(ara[i].sx - ara[i].ex) + abs(ara[i].sy - ara[i].ey);
            for(ll j = i + 1; j <= n; j++) {
                ll tm2 = abs(ara[i].ex - ara[j].sx) + abs(ara[i].ey - ara[j].sy);
                if(ara[i].t + tme + tm2 + 1 <= ara[j].t) {
                    addEdge(i, n + j, 1);
                  }
            }
        }
          for(ll i = 1; i <= n; i++)
            addEdge(n + i, 1003, 1);
          ll bp = maxFlow(0, 1003);
        printf("Case %lld: %lld\n", ++caseno, n - bp);
          for(ll i = 0; i < maxnodes; i++)
            g[i].clear();
    }
      return 0;
}
 
