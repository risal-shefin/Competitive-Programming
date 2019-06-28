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
pair <ll, ll> point[105];
ll ase[105], cap[105];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        double d;
        scanf("%lld %lf", &n, &d);
        double sqd = d * d;
          ll tot = 0;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld %lld %lld", &point[i].first, &point[i].second, &ase[i], &cap[i]);
              tot += ase[i];
        }
            vector <ll> ans;
        for(ll i = 1; i <= n; i++) {
              for(ll j = 0; j < maxnodes; j++)
                g[j].clear();
              for(ll j = 1; j <= n; j++) {
                  addEdge(j, j + 101, cap[j]);
                addEdge(0, j, ase[j]);
                  for(ll k = j + 1; k <= n; k++) {
                      double dis = (point[j].first - point[k].first) * (point[j].first - point[k].first) + (point[j].second - point[k].second) * (point[j].second - point[k].second);
                    if(dis <= sqd) {
                        //cout << j << "  " << k << endl;
                        addEdge(j + 101, k, INT_MAX);
                        addEdge(k + 101, j, INT_MAX);
                    }
                }
            }
              ll tmp = maxFlow(0, i);
              //cout << tmp << endl;
              if(tmp == tot)
                ans.push_back(i - 1);
        }
          printf("Case %lld:", ++caseno);
        for(ll i = 0; i < ans.size(); i++)
            printf(" %lld", ans[i]);
        if(ans.size() == 0)
            printf(" -1");
          printf("\n");
    }
      return 0;
}
 
