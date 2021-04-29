/*
 * Dominator Tree Implementation
 * Source node of the DAG is the root of the Tree.
 * If any Ancestor of u is removed, u will be
   disconnected from the source in the DAG.
 * If u is removed, all the nodes in the subtree
   of u will be disconnected from the source in the DAG.
*/

const ll sz = 1e5 + 10, LN = 18;
vector <ll> dag[sz], par[sz], dom[sz], tops;
ll depth[sz], pa[LN][sz];

/*
 * dag :  stores the DAG
 * som : stores the Dominator Tree
 * par[u] : direct parent of u in the DAG
 * tops : stores the  ascending topsort order of the DAG
*/

ll LCA(ll u, ll v)
{
    if(depth[u] < depth[v]) swap(u,v);
    ll diff = depth[u] - depth[v];
    for(ll i = 0; i < LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
    if(u == v) return u;
    for(ll i = LN-1; i >= 0; i--) {
        if(pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

// Add the node u to the Dominator Tree
void add_node(ll u, ll p)
{
    // Updating the Sparse Table
    pa[0][u] = p;
    for(ll i = 1; i < LN; i++)
        if(pa[i-1][u] != -1)
            pa[i][u] = pa[i-1][ pa[i-1][u] ];

    depth[u] = (p==-1)? 0 : depth[p] + 1;
    if(p != -1) dom[p].push_back(u);
}

void build_dominator_tree()
{
    for(ll &u : tops) {

        if(par[u].empty()) {
            add_node(u, -1);
            continue;
        }

        ll lca = par[u][0];
        for(ll &p : par[u])
            lca = LCA(lca, p);

        add_node(u, lca);
    }
}

void init(ll n)
{
    for(ll i=1; i<=n; i++) {
        dag[i].clear(), par[i].clear();
        dom[i].clear();
        for(ll j=0; j<LN; j++) pa[j][i] = -1;
    }
    tops.clear();
}

// init(n);
// Traverse the DAG and do the necessary things.
// build_dominator_tree(); to build the tree
