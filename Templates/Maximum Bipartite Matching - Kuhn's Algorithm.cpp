// For Maximum Bipartite Matching
// Complexity: O(min(n*m, n^3))

ll l_siz, r_siz; // l_siz = left part size, r_siz = right part size;
vector <ll> g[sz*sz], lft, rgt;
vector <bool> used;

bool try_kuhn(ll v)
{
    for (ll &to : g[v]) {
        if(used[to]) continue;
        used[to] = 1;

        if(rgt[to]==-1 || try_kuhn(rgt[to])) {
            lft[v] = to, rgt[to] = v;
            return true;
        }
    }
    return false;
}

void kuhn()
{
    lft.assign(l_siz+1, -1), rgt.assign(r_siz+1, -1);
    for(ll v=1; v<=l_siz; ++v) {
        used.assign(r_siz+1, false);
        try_kuhn(v);
    }
}
