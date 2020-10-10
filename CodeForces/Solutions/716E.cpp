#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 1e5;
vector <ll> g[MAX + 9], c[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, M, ans = 0, pw[MAX + 9], inv[MAX + 9], depth[MAX + 9];

typedef pair<ll, ll> pii;
#define x first
#define y second

pii extendedEuclid(ll a, ll b)   // returns x, y for ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

ll MODI(ll a, ll m)
{
    pii ret = extendedEuclid(a, m);
    return ((ret.x % m) + m) % m;
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

map <int, int> cntup, upinpath[MAX + 9];

void numdfs(ll u, ll p, ll gp, ll down, ll up, ll d)

{
    if(down == 0) ans++;
    if(up == 0) ans++;

    ll compup = ( (-down * inv[d]) % M + M) % M;
    ans += cntup[compup];
    ans -= upinpath[gp][compup];

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i], cst = c[u][i];
        if(nd == p || del[nd])
            continue;

        numdfs(nd, u, gp, (down * 10 + cst) % M, (cst * pw[d] + up) % M, d + 1);
    }
}

void adfs(ll u, ll p, ll gp, ll down, ll up, ll d)

{
    cntup[up]++;
    upinpath[gp][up]++;

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i], cst = c[u][i];
        if(nd == p || del[nd])
            continue;

        adfs(nd, u, gp, (down * 10 + cst) % M, (cst * pw[d] + up) % M, d + 1);
    }
}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        adfs(nd, cen, nd, c[cen][i] % M, c[cen][i] % M, 1);
    }

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];
        if(del[nd])
            continue;

        numdfs(nd, cen, nd, c[cen][i] % M, c[cen][i] % M, 1);
        upinpath[nd].clear();
    }

    cntup.clear();

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}


int main()

{
    pw[0] = inv[0] = 1;

    ll n;
    cin >> n >> M;

    for(ll i = 1; i <= MAX; i++) {
        pw[i] = (pw[i - 1] * 10) % M;
        inv[i] = MODI(pw[i], M);
    }
    for(ll i = 1; i < n; i++) {
        ll u, v, cst;
        scanf("%lld %lld %lld", &u, &v, &cst);
        g[u].pb(v);
        g[v].pb(u);

        c[u].pb(cst);
        c[v].pb(cst);
    }

    decompose(1, -1);

    cout << ans << endl;

    return 0;
}