#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pb push_back
ll col[450009], fst[450009], start[450009], nodeOf[450009], tme[1000009], lca[3000009];
vector <ll> graph[450009];
ll TM = 1, indx = 0;

bitset <255> cl[450009];

void dfs(ll u, ll p)

{
    start[u] = TM;
    nodeOf[TM] = u;
    TM++;
    tme[indx] = start[u];
    fst[u] = indx;
    indx++;

    cl[u][ col[u] ] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {

        if(graph[u][i] != p) {
            dfs( graph[u][i] , u);
            tme[indx++] = start[u];
            cl[u] |= cl[ graph[u][i] ];
        }
    }
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        lca[node] = tme[lo];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
    lca[node] = min(lca[2 * node], lca[2 * node + 1]);
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 1e18;
    if(lo >= left && hi <= right)
        return lca[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return min(p1, p2);
}

int main()

{
    ll t, n, q, root, u, v, l, r;
    cin >> t;
    while(t--) {
       scanf("%d %d %d", &n, &q, &root);
       for(ll i = 0; i < n; i++)
            scanf("%d", &col[i]);

       for(ll i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

        dfs(root, -1);
        build(0, indx - 1, 1);
        //cout << 5;
        for(ll i = 1; i <= q; i++) {
            scanf("%d %d", &l, &r);
            //cout << fst[l] << "  " <<fst[r] << endl;
            if(fst[l] > fst[r])
                swap(l, r);
            ll lc = query(0, indx - 1, fst[l], fst[r], 1);
            //cout << cl[4].count() << endl;
            printf("%d\n", cl[ nodeOf[lc] ].count());
        }

        for(ll i = 0; i < n; i++) {
            graph[i].clear();
            cl[i].reset();
        }
        TM = 1;
        indx = 0;
    }

    return 0;
}
