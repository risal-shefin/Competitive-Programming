#include <bits/stdc++.h>
using namespace std;
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
    ll id;
    string s1, s2;
      node(ll _id, string _s1, string _s2) {
        id = _id;
        s1 = _s1;
        s2 = _s2;
    }
};
vector <node> A, B;
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll m, f, v;
        cin >> m >> f >> v;
          for(ll i = 1; i <= v; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if(s1[0] == 'M')
                A.push_back( node(i, s1, s2) );
            else
                B.push_back( node(i, s1, s2) );
        }
          for(ll i = 0; i < A.size(); i++) {
              addEdge(0, A[i].id, 1);
            for(ll j = 0; j < B.size(); j++) {
                if( (A[i].s1 == B[j].s2) || (A[i].s2 == B[j].s1) )
                    addEdge(A[i].id, B[j].id, 1);
            }
        }
          for(ll i = 0; i < B.size(); i++)
            addEdge(B[i].id, 1003, 1);
          ll bp = maxFlow(0, 1003);
        cout << "Case " << ++caseno << ": " << v - bp << endl;
          for(ll i = 0; i < maxnodes; i++)
            g[i].clear();
        A.clear();
        B.clear();
    }
      return 0;
}
 
