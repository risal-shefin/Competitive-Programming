#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 1e5;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, ans = 0, val[MAX + 9], freq[32][2];

void add(ll num)

{
    for(ll i = 30; i >= 0; i--) {
        bool state = (num >> i) & 1;
        freq[i][state]++;
    }
}

void query(ll num)

{
    for(ll i = 30; i >= 0; i--) {
        bool state = (num >> i) & 1;
        ans += (freq[i][state ^ 1] * (1 << i));
    }
}

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

void qdfs(ll u, ll p, ll v)

{
    query(v);
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;

        qdfs(nd, u, v ^ val[nd]);
    }
}

void adfs(ll u, ll p, ll v)

{
    add(v);
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;

        adfs(nd, u, v ^ val[nd]);
    }
}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    add(val[cen]);
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        qdfs(nd, cen, val[nd]);
        adfs(nd, cen, val[nd] ^ val[cen]);
    }

    memset(freq, 0, sizeof(freq));

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
        ans += val[i];
    }

    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(1, -1);

    cout << ans << endl;

    return 0;
}