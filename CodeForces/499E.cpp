#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxnodes = 100009;
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
vector <ll> prime, fact[105];
bool mark[31710];
ll st[105], ara[105];
int main()
{
    prime.push_back(2);
    for(ll i = 3; i <= 31700; i += 2)
    {
        if(mark[i] == 0)
        {
            for(ll j = i * i; j <= 31700; j += i + i)
                mark[j] = 1;
            prime.push_back(i);
        }
    }
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &ara[i]);
    }
    ll id = 1;
    for(ll i = 1; i <= n; i++)
    {
        ll tmp = ara[i];
        st[i] = id;
        for(ll j = 0; j < prime.size(); j++)
        {
            if(tmp % prime[j] == 0)
            {
                while(tmp % prime[j] == 0)
                {
                    tmp /= prime[j];
                    id++;
                    fact[i].push_back(prime[j]);
                }
            }
        }
        if(tmp > 1)
        {
            fact[i].push_back(tmp);
            id++;
        }
    }
    st[n + 1] = id;
    for(ll i = 1; i <= m; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        for(ll j = 0; j < fact[a].size(); j++)
        {
            for(ll k = 0; k < fact[b].size(); k++)
            {
                if(fact[a][j] != fact[b][k])
                    continue;
                if(a & 1)
                    addEdge(st[a] + j, st[b] + k, 1);
                else
                    addEdge(st[b] + k, st[a] + j, 1);
            }
        }
    }
    for(ll i = 1; i <= n; i += 2)
        for(ll j = st[i]; j < st[i + 1]; j++)
            addEdge(0, j, 1);
    for(ll i = 2; i <= n; i += 2)
        for(ll j = st[i]; j < st[i + 1]; j++)
            addEdge(j, id, 1);
    cout << maxFlow(0, id) << endl;
    return 0;
}
