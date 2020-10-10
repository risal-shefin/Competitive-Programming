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

const ll sz = 1e5 + 10, LN = 18;
vector <ll> g[sz], index[sz];
ll path[sz], pa[LN][sz], depth[sz], start[sz], stop[sz], TM;
ll incr[2*sz], ans[sz];

void dfs(ll u, ll p)
{
    start[u] = ++TM;
    depth[u] = depth[p] + 1, pa[0][u] = p;

    for(ll i = 0; i < g[u].size(); i++) {
        ll v = g[u][i], idx = index[u][i];
        if(v == p)
            continue;

        path[v] = idx;
        dfs(v, u);
    }
    stop[u] = ++TM;
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

int main()
{
    ll n, u, v, k;
    cin >> n;
    for1(i, (n-1)) {
        sl(u), sl(v);
        g[u].pb(v); g[v].pb(u);
        index[u].pb(i), index[v].pb(i);
    }

    dfs(1, 0);

    for(int i=1; i<LN; i++)
        for(int j=1; j<=n; j++)
            if(pa[i-1][j] != 0)
                pa[i][j] = pa[i-1][pa[i-1][j]];


    cin >> k;
    for1(i, k) {
        sl(u), sl(v);
        ll lc =  LCA(u, v);

        if(lc != u)
            incr[ start[lc] + 1]++, incr[ start[u] + 1]--;
        if(lc != v)
            incr[ start[lc] + 1]++, incr[ start[v] + 1]--;
    }

    for1(i, TM) incr[i] += incr[i-1];

    for1(i, n) {
        ll ase = incr[ start[i] ] - incr[ stop[i] ];
        ans[ path[i] ] += ase;
    }

    for1(i, (n-1)) {
        if(i != 1) pf(" ");
        pf("%lld", ans[i]);
    }
    pn;

    return 0;
}