#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector <ll> graph[100009];
ll col[100009], sz[100009], TM = 1, st[100009], en[100009], nodeOf[200009], cnt[100009];
ll ans[100009], lev[100009], sumLev[100009], mxLv = 0;
bool big[100009];
multiset <ll> sumLst;

void szdfs(ll u, ll p, ll lv)

{
    st[u] = TM;
    nodeOf[TM] = u;
    TM++;
    sz[u] = 1;
    lev[u] = lv;
    mxLv = max(mxLv, lv);
    sumLev[lv] += col[u];

    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        szdfs(nd, u, lv + 1);
        sz[u] += sz[nd];
    }
    en[u] = TM++;
}

void add(ll u, ll p, ll x, ll h)

{
    auto it = sumLst.find(sumLev[h]);
    sumLst.erase(it);

    sumLev[h] -= x * col[u];
    sumLst.insert( sumLev[h] );

    for(auto v: graph[u])
        if(v != p && big[v] != 1)
            add(v, u, x, h + 1);

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

    if(bigChild != -1) {
        dfs(bigChild, u, 1);  /// bigChild marked as big and not cleared from cnt
        big[ bigChild ] = 1;
    }

     add(u, p, 1, lev[u]);
    ///now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    ans[u] = *(--sumLst.end() );

    if(bigChild != -1)
        big[ bigChild ] = 0;
    if(keep == 0)
        add(u, p, -1, lev[u]);
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        TM = 1;
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &col[i]);

        for(ll i = 2; i <= n; i++) {
            ll v;
            scanf("%lld", &v);
            graph[i].pb(v);
            graph[v].pb(i);
        }

        mxLv = 0;

        szdfs(1, -1, 1);

        for(ll i = 1; i <= mxLv; i++)
            sumLst.insert( sumLev[i] );

        dfs(1, -1, 1);

        for(ll i = 2; i <= n; i++)
            printf("%lld\n", ans[i]);

        memset(sumLev, 0, sizeof(sumLev));
        sumLst.clear();
        for(ll i = 1; i <= n; i++)
            graph[i].clear();
    }

    return 0;
}