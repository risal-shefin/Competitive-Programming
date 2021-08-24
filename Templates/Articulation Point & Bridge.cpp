/* For multiple edges between 2 nodes, this code needs modifications for articulation bridge*/
/* Modification area: if(v == p) continue; */
/* Modification Suggestion: Number the edges and use the numbers for pointing edges */

#define ll long long
const ll sz = 100009;
vector <ll> g[sz];
ll low[sz], start[sz], TM = 1, root = 1;
bool artPoint[sz], vis[sz];

void artdfs(ll u, ll p)
{
    low[u] = start[u] = TM++;
    vis[u] = 1;
    ll child = 0;       /// Counter of the children of u in dfs tree
    for(ll i = 0; i < g[u].size(); i++) {
        ll v = g[u][i];
        if(v == p)
            continue;

        if(vis[v])
            low[u] = min(low[u], start[v]);
        else {
            artdfs(v, u);
            low[u] = min(low[u], low[v]);

            if(start[u] <= low[v] && u != root) {    /// For articulation bridge: if(start[u] < low[v])
                artPoint[u] = true;                             /// the edge between u and v is an articulation bridge
            }
            child++;
        }
    }

    if(child > 1 && u == root)  /// For articulation bridge: this
        artPoint[u] = true;     /// and this line have no need
}

// artdfs(root, -1)
