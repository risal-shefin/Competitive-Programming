// For Maximum Bipartite Matching
// Complexity: O(min(n*m, n^3))

ll n, k; // n = left part size, k = right part size;
vector <ll> g[1500], lft, rgt;
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
    lft.assign(n+1, -1), rgt.assign(k+1, -1);
    for(ll v=1; v<=n; ++v) {
        used.assign(k+1, false);
        try_kuhn(v);
    }
}
