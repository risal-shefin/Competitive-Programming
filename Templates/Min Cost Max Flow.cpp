const ll maxnodes = 10005;

ll nodes = maxnodes, src, dest;
ll dist[maxnodes], exist[maxnodes];
pll par[maxnodes];

struct Edge
{
    ll to, rev;
    ll f, cap, cost;
};

vector<Edge> g[maxnodes];

void addEdge(ll s, ll t, ll cap, ll cost)
{
    Edge a = {t, g[t].size(), 0, cap, cost};
    Edge b = {s, g[s].size(), 0, 0, -cost};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool spfa()
{
    fill(dist, dist + nodes, inf);
    fill(exist, exist + nodes, 0);

    dist[src] = 0, exist[src] = 1;
    queue <ll> q;
    q.push(src);

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        exist[u] = 0;

        for(ll i = 0; i < g[u].size(); i++) {

            Edge e = g[u][i];

            if(dist[e.to] > dist[u] + e.cost && e.f < e.cap) {

                dist[e.to] = dist[u] + e.cost;
                par[e.to] = mp(u, i);

                if(!exist[e.to]) {
                    q.push(e.to);
                    exist[e.to] = 1;
                }

            }
        }
    }

    return dist[dest] != inf;
}

pll minCostMaxFlow(ll _src, ll _dest)
{
    src = _src;
    dest = _dest;
    pll result = mp(0,0);
    while (spfa())
    {
        ll cur = _dest, flow = inf;
        while(cur != _src) {
            ll p = par[cur].first;
            Edge e = g[p][ par[cur].second ];
            flow = min(flow, e.cap - e.f);

            cur = p;
        }
        result.first += flow;

        cur = _dest;
        while(cur != _src) {
            ll p = par[cur].first;
            Edge &e = g[p][ par[cur].second ];

            e.f += flow;
            g[e.to][e.rev].f -= flow;

            result.second += flow * e.cost;

            cur = p;
        }
    }
    return result;
}
// addEdge(u, v, C, cst); edge from u to v. Capacity=C, Cost=cst.
// minCostMaxFlow(s, t); min cost max flow from s to t
