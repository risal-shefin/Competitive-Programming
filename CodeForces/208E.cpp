#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> graph[100009], root;
vector < pair <ll, ll> > qry[100009];
ll col[100009], sz[100009], TM = 1, st[100009], en[100009], nodeOf[200009], cnt[100009], lev[100009];
ll ans[100009], table[100009][20], MLOG, n;
void szdfs(ll u, ll p, ll lv)
{
    st[u] = TM;
    nodeOf[TM] = u;
    lev[u] = lv;
    TM++;
    sz[u] = 1;
    table[u][0] = p;
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
                cnt[ lev[ nodeOf[t] ] ]++;
    cnt[ lev[u] ]++;
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    for(ll i = 0; i < qry[u].size(); i++) {
        ll lv = qry[u][i].first;
        ll id = qry[u][i].second;
        ans[id] = cnt[lev[u] + lv] - 1;
    }
    if(keep == 0)
        for(ll t = st[u]; t < en[u]; t++)
            cnt[ lev[ nodeOf[t] ] ]--;
}
void build()
{
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= MLOG; j++) {
            table[i][j] = table[ table[i][j - 1] ][j - 1];
        }
    }
}
ll kth(ll u, ll k)
{
    for(ll i = MLOG; i >= 0; i--) {
        if( (1 << i) <= k) {
            u = table[u][i];
            k -= (1 << i);
        }
    }
    return u;
}
int main()
{
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        if(x == 0) {
            root.push_back(i);
            continue;
        }
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    ll pw = 1, log2 = 1;
    while(pw <= n) {
        pw <<= 1;
        log2++;
    }
    MLOG = log2;
    for(ll i = 0; i < root.size(); i++)
        szdfs(root[i], 0, 1);
    build();
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        ll v, l;
        scanf("%lld %lld", &v, &l);
        //cout << 5 << endl;
        ll par = kth(v, l);
        if(par != 0)
            qry[par].push_back( make_pair(l, i) );
    }
    for(ll i = 0; i < root.size(); i++) {
        dfs(root[i], 0, 0);
        cnt[0] = 0;
    }
    for(ll i = 1; i <= q; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", ans[i]);
    }
    cout << endl;
    return 0;
}
