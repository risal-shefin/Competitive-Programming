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
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll siz = 1e5 + 10;
ll n, m;

struct info {
    ll v1, v2;
} diag[siz];

const bool operator <(const info &a, const info &b) {

    ll aTotalNodes = min(a.v2-a.v1-1, n-2 - (a.v2-a.v1-1));
    ll bTotalNodes = min(b.v2-b.v1-1, n-2 - (b.v2-b.v1-1));

    return aTotalNodes < bTotalNodes;
}

vector <int> region[siz];
unordered_map <int, int> dreg[siz];

const ll MAX = 1e5;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, col[siz];

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

void decompose(ll u, ll p, ll lev)
{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1)
        p = cen;
    par[cen] = p, del[cen] = 1, col[cen] = lev;

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen, lev+1);
    }
}

int main()
{
    cin >> n >> m;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        if(u > v) swap(u, v);

        diag[i] = {u, v};
    }
    sort(diag+1, diag+m+1);

    set <int> vertex;
    for1(i, n) vertex.insert(i);

    for1(i, m) {
        ll dwn = diag[i].v2-diag[i].v1-1, up = n-2 - dwn;

        if(dwn <= up) {
            region[i].pb(diag[i].v1);

            auto it = vertex.upper_bound(diag[i].v1);

            while(*it != diag[i].v2) region[i].pb(*it), ++it;
            region[i].pb(diag[i].v2);

            for(ll j = 1; j+1 < region[i].size(); j++) vertex.erase(region[i][j]);
        }
        else {
            while(*vertex.begin() != diag[i].v1) {
                region[i].pb(*vertex.begin());
                vertex.erase(vertex.begin());
            }
            region[i].pb(diag[i].v1);

            while(*vertex.rbegin() != diag[i].v2) {
                region[i].pb(*vertex.rbegin());
                vertex.erase(*vertex.rbegin());
            }
            region[i].pb(diag[i].v2);
        }

        sort(all(region[i]), greater<int>());
    }

    ll idx = m+1;
    while(!vertex.empty()) {
        region[idx].pb(*vertex.rbegin());
        vertex.erase(*vertex.rbegin());
    }

    sort(region+1, region+idx+1);

    for1(i, idx) {

        for(int j = 0; j < region[i].size(); j++) {

            int nxt = (j+1) % region[i].size();
            int v1 = region[i][j], v2 = region[i][nxt];

            if(v1 > v2) swap(v1, v2);

            if(dreg[v1].find(v2) == dreg[v1].end())
                dreg[v1][v2] = i;
            else {
                int reg = dreg[v1][v2];

                g[reg].pb(i);
                g[i].pb(reg);
            }
        }
    }

    decompose(1, -1, 1);

    for1(i, idx) {
        if(i != 1) pf(" ");
        pf("%lld", col[i]);
    }
    pn;

    return 0;
}