#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 305;
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
        vector <ll> small, big;
        ll n, d;
        scanf("%lld %lld", &n, &d);
          for(ll i = 1; i <= n; i++) {
            char ch;
            ll dis;
            scanf(" %c-%lld", &ch, &dis);
            if(ch == 'B')
                big.push_back(dis);
            else
                small.push_back(dis);
        }
          ll lo = 1, hi = 1e9 + 9, ans, bs = big.size();
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
              for(ll i = 0; i < big.size(); i++) {
                if(big[i] <= mid)
                    addEdge(0, i + 1, INT_MAX);
                  if(d - big[i] <= mid)
                    addEdge(i + 1, 303, INT_MAX);
                  for(ll j = i + 1; j < big.size(); j++) {
                    if(big[j] - big[i] <= mid)
                        addEdge(i + 1, j + 1, INT_MAX);
                }
                  for(ll j = 0; j < small.size(); j++) {
                    if(small[j] - big[i] <= mid && small[j] > big[i])
                        addEdge(i + 1, bs + j + 1, 1);
                      if(big[i] - small[j] <= mid && small[j] < big[i])
                        addEdge(bs + j + 1 + 101, i + 1, 1);
                }
            }
              for(ll i = 0; i < small.size(); i++) {
                  addEdge(bs + i + 1, bs + i + 1 + 101, 1);
                if(small[i] <= mid)
                    addEdge(0, bs + i + 1, 1);
                if(d - small[i] <= mid)
                    addEdge(bs + i + 1 + 101, 303, 1);
                  for(ll j = i + 1; j < small.size(); j++) {
                    if(small[j] - small[i] <= mid)
                        addEdge(bs + i + 1 + 101, bs + j + 1, 1);
                }
            }
              if(d <= mid)
                addEdge(0, 303, INT_MAX);
              ll tmp = maxFlow(0, 303);
              if(tmp >= 2) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
              for(ll i = 0; i < maxnodes; i++)
                g[i].clear();
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
