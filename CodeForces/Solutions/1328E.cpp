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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10, LN = 18;;
vector <ll> g[sz];
pll ara[sz];
ll pa[LN][sz], depth[sz];

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

void dfs(ll u, ll p, ll lv)
{
    depth[u] = lv;
    pa[0][u] = p;

    for(ll v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u, lv + 1);
    }
}

int main()
{
    ll n, q;
    cin >> n >> q;
    for1(i, (n-1)) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    ms(pa, -1);
    dfs(1, -1, 1);

    for(int i=1; i<LN; i++)
        for(int j=1; j<=n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];


    while(q--) {
        ll num;
        sl(num);

        for1(i, num) {
            sl(ara[i].second);
            ara[i].first = depth[ ara[i].second ];
        }
        sort(ara+1, ara+num+1, greater <pll> ());

        bool chk = 1, path = 0;
        ll lc = ara[1].second;
        for(ll i = 2; i <= num; i++) {
            ll now = LCA(lc, ara[i].second);

            ll d1 = depth[lc] - depth[now];
            ll d2 = ara[i].first - depth[now];

            if(d1 > 1 && d2 > 1) {
                chk = 0;
                break;
            }

            if(d2 > 1) {
                if(path) {
                    chk = 0;
                    break;
                }
                path = 1;
            }
            if(d1 >= 1 || d2 == 1)
                path = 1;

            lc = now;
        }

        if(chk)
            pf("YES\n");
        else
            pf("NO\n");
    }

    return 0;
}