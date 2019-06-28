#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 10005;
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
pair <ll, ll> per[405], taxi[205];
int main()
 {
    ll T;
    cin >> T;
    while(T--) {
        ll p, t, s, c;
        scanf("%lld %lld %lld %lld", &p, &t, &s, &c);
         for(ll i = 1; i <= p; i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
             per[i] = make_pair(x, y);
        }
         for(ll i = 1; i <= t; i++) {
             ll x, y;
            scanf("%lld %lld", &x, &y);
             taxi[i] = make_pair(x, y);
        }
         for(ll i = 1; i <= t; i++) {
             for(ll j = 1; j <= p; j++) {
                ll dist = abs(per[j].first - taxi[i].first) + abs(per[j].second - taxi[i].second);
                 if(dist * 200 <= s * c)
                    addEdge(i, j + t, 1);
            }
        }
         for(ll i = 1; i <= t; i++)
            addEdge(0, i, 1);
        for(ll i = 1; i <= p; i++)
            addEdge(i + t, t + p + 1, 1);
         printf("%lld\n", maxFlow(0, t + p + 1));
         for(ll i = 0; i < maxnodes; i++) {
            g[i].clear();
            dist[i] = 0;
            q[i] = 0;
            work[i] = 0;
        }
     }
     return 0;
}
