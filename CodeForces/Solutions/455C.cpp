// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, heighteof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 3e5 + 10;
vector <ll> g[sz];
bool vis[sz];
ll par[sz], height[sz], len[sz], mxu, mxd;

void dfs(ll u, ll p, ll d)
{
    if(d > mxd) {
        mxd = d;
        mxu = u;
    }

    vis[u] = 1;
    for(ll &v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u, d+1);
    }
}

void assign_dfs(ll u, ll p)
{
    par[u] = mxu;

    for(ll &v : g[u]) {
        if(v == p)
            continue;

        assign_dfs(v, u);
    }
}

ll findPar(ll u)
{
    if(par[u] == u) return u;
    return par[u] = findPar(par[u]);
}

void Union(ll x, ll y)
{
    if(height[x] < height[y]) swap(x, y);
    if(height[x] == height[y]) height[x]++;

    par[y] = x;

    ll lenx = len[x] / 2, leny = len[y] / 2;
    if(len[x] & 1) lenx++;
    if(len[y] & 1) leny++;

    len[x] = max({len[x], len[y], lenx + leny + 1});
}

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) {
        if(vis[i]) continue;

        mxd = -1;
        dfs(i, -1, 0);

        mxd = -1;
        dfs(mxu, -1, 0);

        assign_dfs(mxu, -1);

        height[mxu] = mxd+1, len[mxu] = mxd;
    }

    while(q--) {
        ll op, x, y;
        sl(op);

        if(op == 1) {
            sl(x);
            ll px = findPar(x);
            pf("%lld\n", len[px]);
        }
        else {
            sl(x), sl(y);

            ll px = findPar(x), py = findPar(y);
            if(px == py)
                continue;

            Union(px, py);
        }
    }

    return 0;
}