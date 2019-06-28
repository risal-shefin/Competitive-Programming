#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct nd {
    ll f;
    ll s;
};
vector <ll> graph[100009], root;
string col[100009];
ll sz[100009], TM = 1, st[100009], en[100009], nodeOf[200009], cnt[100009], lev[100009];
ll ans[100009];
vector < nd > qry[100009];
set <string> name[200009];
void szdfs(ll u, ll p, ll lv)
{
    st[u] = TM;
    nodeOf[TM] = u;
    lev[u] = lv;
    TM++;
    sz[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        szdfs(nd, u, lv + 1);
        sz[u] += sz[nd];
    }
    en[u] = TM++;
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
    if(bigChild != -1)
        dfs(bigChild, u, 1);  /// bigChild marked as big and not cleared from cnt
    for(auto v : graph[u])
        if(v != p && v != bigChild)
            for(ll t = st[v]; t < en[v]; t++)
                name[ lev[ nodeOf[t] ] ].insert( col[ nodeOf[t] ]);
    name[ lev[u] ].insert( col[u] );
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    for(ll i = 0; i < qry[u].size(); i++) {
        ll level = qry[u][i].f;
        ll id = qry[u][i].s;
        //cout << lev[u] + level << " cgjf " << endl;
        ans[id] = name[ lev[u] + level ].size();
    }
    if(keep == 0)
        for(ll t = st[u]; t < en[u]; t++)
            name[ lev[ nodeOf[t] ] ].erase( col[ nodeOf[t] ]);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n, cap;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> col[i];
        ll p;
        cin >> p;
        if(p == 0) {
            root.push_back(i);
            continue;
        }
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
    for(ll i = 0; i < root.size(); i++)
        szdfs(root[i], -1, 0);
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        ll v, lv;
        cin >> v >> lv;
        struct nd tmp;
        tmp.f = lv, tmp.s = i;
        qry[v].push_back( tmp );
    }
    for(ll i = 0; i < root.size(); i++)
        dfs(root[i], -1, 0);
    for(ll i = 1; i <= q; i++)
        cout << ans[i] << endl;
    return 0;
}
