#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 5e4;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], ans = 0, curSize;
ll cnt[509], k;

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
        if(nd == p || del[nd] || sz[nd] <= curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}

void countdfs(ll u, ll p, ll d)

{
    if(d <= k)
        ans += cnt[k - d];

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;

        countdfs(nd, u, d + 1);
    }
}

void adddfs(ll u, ll p, ll d)

{
    if(d <= k)
        cnt[d]++;

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;

        adddfs(nd, u, d + 1);
    }
}

void deldfs(ll u, ll p, ll d)

{
    if(d <= k)
        cnt[d]--;

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;

        deldfs(nd, u, d + 1);
    }
}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    cnt[0]++;
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        countdfs(nd, cen, 1);
        adddfs(nd, cen, 1);
    }

    cnt[0]--;
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        deldfs(nd, cen, 1);
    }

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}

int main()

{
    ll n;
    cin >> n >> k;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    decompose(1, -1);

    cout << ans << endl;

    return 0;
}