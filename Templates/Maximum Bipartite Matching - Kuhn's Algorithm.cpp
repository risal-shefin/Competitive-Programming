// For Maximum Bipartite Matching
// Complexity: O(min(n*m, n^3))

ll l_siz, r_siz; // l_siz = left part size, r_siz = right part size;
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

ll kuhn()
{
    ll max_match = 0;
    lft.assign(l_siz+1, -1), rgt.assign(r_siz+1, -1);
    for(ll v=1; v<=l_siz; ++v) {
        used.assign(r_siz+1, false);
        max_match += try_kuhn(v);
    }
    return max_match;
}

/* Optimized Kuhn's Algorithm. Blog: https://codeforces.com/blog/entry/17023 */
ll kuhn2()
{
    ll max_match = 0;
    lft.assign(l_siz+1, -1), rgt.assign(r_siz+1, -1);
    
    // Shuffle the left part randomly to traverse them randomly
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // Random Seed
    vector <ll> lft_part;
    for(ll v=1; v<=l_siz; ++v) lft_part.push_back(v);
    shuffle(lft_part.begin(), lft_part.end(), rng);
    
    // Greedy matching with adjacent nodes at first
    for(auto &v : lft_part) {
        // Shuffle the adjacent nodes to match them randomly
        shuffle(g[v].begin(), g[v].end(), rng);
        
        for(auto &to : g[v]) {
            if(rgt[to] == -1) {
                lft[v] = to, rgt[to] = v;
                max_match++;
                break;
            }
        }
    }
    
    // Main Kuhn's Algorithm Part
    bool new_mat = 1;
    while(new_mat) {
        // used is cleared one time in each iteration so that we can find several
        // matchings in O(E). This makes the whole algorithm significantly faster.
        used.assign(r_siz+1, false);
        // If no new match is found, the loop will break
        new_mat = 0;

        for(auto &v : lft_part) {
            if(lft[v] != -1)
                continue;
            
            bool got = try_kuhn(v);
            max_match += got, new_mat |= got;
        }
    }
    return max_match;
}

