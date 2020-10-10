#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pb push_back

#define root 0
#define N 10100
#define LN 14

vector <int> g[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], subsize[N];
int st[N*6], st2[N*6], qt[N*6], lazy[N*6];

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(int cur, int s, int e) {
	if(s == e-1) {
		st[cur] = st2[cur] = baseArray[s];
		lazy[cur] = 0;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	st2[cur] = st2[c1] < st2[c2] ? st2[c1] : st2[c2];
	lazy[cur] = 0;
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi - 1)
        return;

    st[2*node] += lazy[node];
    st[2*node + 1] += lazy[node];

    st2[2*node] += lazy[node];
    st2[2*node + 1] += lazy[node];

    lazy[2*node] += lazy[node];
    lazy[2*node + 1] += lazy[node];

    lazy[node] = 0;
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(int cur, int s, int e, int l, int r, int val) {
    if(lazy[cur] != 0) prop(s, e, cur);
	if(s >= r || e <= l) return;
	if(s >= l && e <= r) {
		st[cur] += val;
		st2[cur] += val;
		lazy[cur] += val;
		//cout << s << "  " << e << " " << val << " " << l << " " << r << " " << st[cur] << endl;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, l, r, val);
	update_tree(c2, m, e, l, r, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	st2[cur] = st2[c1] < st2[c2] ? st2[c1] : st2[c2];
}

void update_up(ll u, ll v, ll val) {
    //cout << u << " " << v << endl;
	if(u == v) { // Trivial
        update_tree(1, 0, ptr, posInBase[u], posInBase[u] + 1, val);
        return;
	}
	int uchain, vchain = chainInd[v], ans = -1;
	// uchain and vchain are chain numbers of u and v
	bool chk = 0;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			//cout << u << " " << v << endl;
			if(u == v) {
                update_tree(1, 0, ptr, posInBase[u], posInBase[u] + 1, val);
                break;
			}
			update_tree(1, 0, ptr, posInBase[v], posInBase[u]+1, val);
			// Above is call to segment tree query function
			break;
		}
		//cout << u << "  " << v << endl;
		update_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1, val);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
		chk = 1;
	}
}

void update(ll u, ll v, ll val) {
    ll lca = LCA(u, v);

    //cout << u << " " << v << " " << lca << endl;

    update_up(u, lca, val);
    update_up(v, lca, val);

    update_up(lca, lca, -val);
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
void query_tree(int cur, int s, int e, int S, int E, int val) {
    if(lazy[cur] != 0) prop(s, e, cur);
    //cout << s << " " << e << " " << S << " " << E << endl;
	if(s >= E || e <= S || st[cur] != val) {
		qt[cur] = 0;
		return;
	}
	if(s >= S && e <= E) {
		if(st[cur] == val && st2[cur] == val) {
            qt[cur] = e - s;
            //cout << qt[cur] << " " << S << " " << E << " " << s << "  " << e << endl;
            return;
		}
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E, val);
	query_tree(c2, m, e, S, E, val);
	qt[cur] = qt[c1] + qt[c2];
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v, int val) {
	if(u == v) {// Trivial
        query_tree(1, 0, ptr, posInBase[u], posInBase[u] + 1, val);
        return qt[1];
	}
	int uchain, vchain = chainInd[v], ans = 0;
	// uchain and vchain are chain numbers of u and v
	bool chk = 0;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			if(u == v) {
                query_tree(1, 0, ptr, posInBase[u], posInBase[u] + 1, val);
                ans += qt[1];
                break;
			}
			query_tree(1, 0, ptr, posInBase[v], posInBase[u]+1, val);
			// Above is call to segment tree query function
			ans += qt[1]; // Update answer
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1, val);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		ans += qt[1];
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
		chk = 1;
	}
	return ans;
}

void query(int u, int v, int val) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ans = query_up(u, lca, val); // One part of path
	int temp = query_up(v, lca, val); // another part of path
	ans += temp; // take the maximum of both paths
	ans -= query_up(lca, lca, val);
	printf("%d\n", ans);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;

	int sc = -1, ncost;
	// Loop to find special child
	for(int i=0; i<g[curNode].size(); i++) if(g[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[g[curNode][i]]) {
			sc = g[curNode][i];
			ncost = 0;
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<g[curNode].size(); i++) if(g[curNode][i] != prev) {
		if(sc != g[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(g[curNode][i], 0, curNode);
		}
	}
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<g[cur].size(); i++)
		if(g[cur][i] != prev) {
			dfs(g[cur][i], cur, _depth+1);
			subsize[cur] += subsize[g[cur][i]];
		}
}

pair <ll, ll> qry[55];

int main()

{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
			g[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}

        for(ll i = 1; i < n; i++) {
            ll u, v;
            scanf("%d %d", &u, &v);
            u--, v--;

            g[u].pb(v);
            g[v].pb(u);
        }

		chainNo = ptr = 0;
		dfs(root, -1); // We set up subsize, depth and parent for each node
		HLD(root, 0, -1); // We decomposed the tree and created baseArray
		make_tree(1, 0, ptr); // We use baseArray and construct the needed segment tree

		// Below Dynamic programming code is for LCA.
		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

        ll q;
        scanf("%d", &q);
        printf("Case %d:\n", ++cs);
        while(q--) {
            ll k;
            scanf("%d", &k);

            for(ll i = 1; i <= k; i++) {
                ll u, v;
                scanf("%d %d", &u, &v);
                u--, v--;

                update(u, v, 1);
                qry[i] = make_pair(u, v);

                //if(i==2)query(0, 0, 2);

                if(i == k) query(u, v, k);
            }

            for(ll i = 1; i <= k; i++)
                update(qry[i].first, qry[i].second, -1);
        }

    }

    return 0;
}