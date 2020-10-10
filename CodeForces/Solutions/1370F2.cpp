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

const ll sz = 1e3 + 10;
vector <ll> g[sz], lvl[sz], q;
ll mxd;
string verd;

inline pll ask()
{
    cout << "? " << q.size();
    for(ll &nd: q) cout << " " << nd;
    cout << endl;

    ll x, d;
    cin >> x >> d;
    return mp(x, d);
}

void dfs(ll u, ll p, ll lev)
{
    lvl[lev].pb(u), mxd = max(mxd, lev);

    for(ll &v: g[u]) if(v != p) dfs(v, u, lev+1);
}

void nodeList(ll u, ll p, ll lev, ll d)
{
    if(lev == d) q.pb(u);

    for(ll &v: g[u]) if(v != p) nodeList(v, u, lev+1, d);
}

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n, u, v;
        cin >> n;

        for1(i, (n-1)) {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        for1(i, n) q.pb(i);
        pll got = ask();
        ll root = got.first;

        mxd = 0;
        dfs(got.first, -1, 0);

        ll d = got.second, lo = d/2, hi = min(mxd, d), node1;
        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            q = lvl[mid];
            got = ask();

            if(got.second == d) {
                node1 = got.first;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        q.clear();
        nodeList(node1, -1, 0, d);
        got = ask();

        ll node2 = got.first;

        cout << "! " << node1 << " " << node2 << endl;
        cin >> verd;
        if(verd[0] == 'I') exit(0);

        for1(i, n) g[i].clear();
        for(ll i = 0; i <= mxd; i++) lvl[i].clear();
        q.clear();
    }

    return 0;
}