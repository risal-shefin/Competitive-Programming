#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const ll MAX = 1e5;
vector <ll> g[MAX + 9], cenTree[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize;
char col[MAX + 9];

void dfs(ll u, ll p)

{
    sz[u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        dfs(nd, u);
        sz[u] += sz[nd];
    }
}

ll findCentroid(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd] || sz[nd] < curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}

void decompose(ll u, ll p, char ch)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen, ch + 1);
    }

    col[cen] = ch;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(1, -1, 'A');

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%c", col[i]);
    }

    cout << endl;

    return 0;
}