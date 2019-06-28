#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> graph[200009];
vector < pair <ll, ll> > qry[100009];
ll col[100009], sz[100009], TM = 1, st[100009], en[100009], nodeOf[200009], cnt[100009];
ll ans[100009];
unordered_map <ll, ll> ase;
void szdfs(ll u, ll p)
{
    st[u] = TM;
    nodeOf[TM] = u;
    TM++;
    sz[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        szdfs(nd, u);
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
            for(ll t = st[v]; t < en[v]; t++) {
                cnt[ col[ nodeOf[t] ] ]++;
                ase[ cnt[ col[ nodeOf[t] ] ] ]++;
            }
    cnt[ col[u] ]++;
    ase[ cnt[ col[u] ] ]++;
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    for(ll i = 0; i < qry[u].size(); i++) {
        ll lv = qry[u][i].first;
        ll id = qry[u][i].second;
        //cout << ase[lv] << "  ff " << u << "  " << lv << endl;
        ans[id] = ase[lv];
    }
    if(keep == 0)
        for(ll t = st[u]; t < en[u]; t++) {
            ase[ cnt[ col[ nodeOf[t] ] ] ]--;
            cnt[ col[ nodeOf[t] ] ]--;
        }
}
int main()
{
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &col[i]);
    }
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(ll i = 1; i <= q; i++) {
        ll v, num;
        scanf("%lld %lld", &v, &num);
        qry[v].push_back( make_pair(num, i) );
    }
    szdfs(1, -1);
    dfs(1, -1, 0);
    for(ll i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
