#define ll long long
#define maxn 100009

vector <ll> graph[maxn];
ll col[maxn], sz[maxn], cnt[maxn], ans[maxn];
bool big[maxn];

void szdfs(ll u, ll p)

{
    sz[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        szdfs(nd, u);
        sz[u] += sz[nd];
    }
}

void add(ll u, ll p, ll x)
{
    cnt[ col[u] ] += x;
    for(auto v: graph[u])
        if(v != p && !big[v])
            add(v, u, x);
}

void dfs(ll u, ll p, bool keep)
{
    ll mx = -1, bigChild = -1;
    for(auto v : graph[u])
        if(v != p && sz[v] > mx)
            mx = sz[v], bigChild = v;

    for(auto v : graph[u])
        if(v != p && v != bigChild)
            dfs(v, u, 0);  /// run a dfs on small childs and clear them from cnt

    if(bigChild != -1) {
        dfs(bigChild, u, 1);
        big[bigChild] = 1;  /// bigChild marked as big and not cleared from cnt
    }

    add(u, p, 1);
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(u, p, -1);
}
//szdfs(1,-1); dfs(1,-1,0);
