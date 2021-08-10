// LRFlow -> Max Flow with [l_i, r_i] range's flow in edges
struct LRFlow {
    struct edge {
        int u, v; ll lo,hi; int id;
    };
    vector <edge> E;
    int N, superSource, superSink;

    void init(int n) {
        N = n+10;
        superSource = n+1, superSink = n+2;
        E.clear();
    }

    void addEdgeLR(int u, int v, ll lo, ll hi, int id=-1) {
        E.pb({u, v, lo, hi, id});
    }

    bool feasible(int s, int t, ll lo=-1, ll hi=-1) {
        if(lo != -1) E.pb({t, s, lo, hi, -1});
        for0(i, N) g[i].clear(); // Clear the flow graph
        ll target = 0;

        for(edge &e : E) {
            if(e.lo>0) {
                addEdge(superSource, e.v, e.lo);
                addEdge(e.u, superSink, e.lo);
                target += e.lo;
            }
            addEdge(e.u, e.v, e.hi-e.lo);
        }
        ll flow = maxFlow(superSource, superSink);
        if(lo != -1) E.pop_back();
        if(flow < target) return false;
        return true;
    }

    ll maxFlowLR(ll s, ll t) {
        if(!feasible(s, t, 0, inf)) return -1;
        return maxFlow(s, t);
    }
};
// LRFlow lrf = LRFlow();
// lrf.init(n); to initialize with n nodes
// lrf.addEdgeLR(u, v, l, r, i); edge_i from u to v. Capacity = [L,R]
// lrf.maxFlowLR(s, t); max flow from s to t satisfying [l_i, r_i] range flows of edges
// g[], maxFlow(s, t), addEdge(u, v, c) are from typical max flow algo.

