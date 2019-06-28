#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxnodes = 450;
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
    char grid[25][25];
ll id = 1, n, m;
ll row[] = {1, -1, 0, 0};
ll col[] = {0, 0, 1, -1};
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        map < pair <ll, ll>, ll> nid;
        id = 1;
        scanf("%lld %lld", &n, &m);
          for(ll i = 1; i <= n; i++)
            scanf("%s", grid[i] + 1);
          ll cnt = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                if(grid[i][j] == '*') {
                    cnt++;
                    if( (i + j) % 2 == 0)
                        continue;
                      ll tid = id++;
                    addEdge(0, tid, 1);
                      for(ll k = 0; k < 4; k++) {
                        ll r = i + row[k];
                        ll c = j + col[k];
                          if(r < 1 || c < 1 || r > n || c > m)
                            continue;
                        if(grid[r][c] != '*')
                            continue;
                          if(nid[ make_pair(r, c) ] == 0) {
                            addEdge(id, 440, 1);
                            addEdge(tid, id, 1);
                            nid[ make_pair(r, c) ] = id;
                            id++;
                        }
                        else
                            addEdge(tid, nid[ make_pair(r, c) ], 1);
                          //cout << i << " " << j << "  lll " << r << " " << c << endl;
                    }
                }
            }
        }
          ll bp = maxFlow(0, 440);
        printf("Case %lld: %lld\n", ++caseno, cnt - bp);
          for(ll i = 0; i < maxnodes; i++)
            g[i].clear();
    }
      return 0;
}
 
