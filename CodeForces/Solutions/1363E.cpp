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
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;
vector <ll> g[sz];
ll cst[sz], b[sz], c[sz], zw[sz], ow[sz];

void dfs(ll u, ll p, ll cost)
{
    cst[u] = cost;

    for(ll &v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u, min(cost, cst[v]));
    }
}

ll solve_dfs(ll u, ll p)
{
    if(b[u] != c[u]) {
        if(b[u] == 0) zw[u] = 1;
        else ow[u] = 1;
    }

    ll ret = 0;
    for(ll &v : g[u]) {
        if(v == p)
            continue;

        ret += solve_dfs(v, u);

        zw[u] += zw[v];
        ow[u] += ow[v];
    }

    ll mn = min(zw[u], ow[u]);
    zw[u] -= mn, ow[u] -= mn;

    //cout << u << " " << mn << " || " << zw[u] << " || " << ow[u] << endl;

    return ret + cst[u] * 2 * mn;
}

int main()
{
    ll n;
    cin >> n;

    for1(i, n) {
        sl(cst[i]), sl(b[i]), sl(c[i]);
    }

    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1, cst[1]);
    ll ans = solve_dfs(1, -1);

    if(zw[1] != 0 || ow[1] != 0) {
        pf("-1\n");
        return 0;
    }

    pf("%lld\n", ans);

    return 0;
}