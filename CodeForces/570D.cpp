#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair <ll, ll>
vector <ll> graph[500009];
vector <pii> qry[500009];
ll col[500009], sz[500009], TM = 1, st[500009], en[500009], nodeOf[1000009], cnt[500009][30], lev[500009];
ll ans[500009];
void szdfs(ll u, ll p, ll lv = 1)
{
    st[u] = TM;
    nodeOf[TM] = u;
    TM++;
    sz[u] = 1;
    lev[u] = lv;
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
                cnt[ lev[ nodeOf[t] ] ][ col[ nodeOf[t] ] ]++;
    cnt[ lev[u] ][ col[u] ]++;
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    for(ll i = 0; i < qry[u].size(); i++) {
        ll odd = 0;
        ll tl = qry[u][i].first;
        for(ll j = 1; j <= 26; j++) {
            if(cnt[tl][j] % 2 != 0)
                odd++;
        }
        if(odd > 1)
            ans[ qry[u][i].second ] = 0;
        else
            ans[ qry[u][i].second ] = 1;
    }
    if(keep == 0)
        for(ll t = st[u]; t < en[u]; t++)
            cnt[ lev[ nodeOf[t] ] ][ col[ nodeOf[t] ] ]--;
}
int main()
{
    ll n, q;
    cin >> n >> q;
    for(ll i = 2; i <= n; i++) {
        ll p;
        scanf("%lld", &p);
        graph[i].pb(p);
        graph[p].pb(i);
    }
    for(ll i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);
        col[i] = ch - 'a' + 1;
    }
    for(ll i = 1; i <= q; i++) {
        ll v, d;
        scanf("%lld %lld", &v, &d);
        qry[v].pb( make_pair(d, i) );
    }
    szdfs(1, -1);
    dfs(1, -1, 0);
    for(ll i = 1; i <= q; i++) {
        if(ans[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
