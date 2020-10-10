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

const ll sz = 1e6 + 10;
vector <ll> g[sz], rev[sz], jury, cat;
stack <ll> topsort;
bool vis[sz];
ll idc, comp[sz];

void dfs(ll u)
{
    vis[u] = 1;
    for(ll &v : g[u])
        if(!vis[v]) dfs(v);

    topsort.push(u);
}

void scc(ll u, ll id)
{
    comp[u] = id;
    for(ll &v : rev[u])
        if(!comp[v]) scc(v, id);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, u, v;
        sl(n), sl(m);

        for1(i, m) {
            sl(u), sl(v);
            g[u].pb(v);
            rev[v].pb(u);
        }

        for1(i, n) {
            if(!vis[i])
                dfs(i);
        }

        idc = 0;
        while(!topsort.empty()) {
            ll u = topsort.top();
            topsort.pop();

            if(!comp[u]) scc(u, ++idc);
        }

        for1(i, n) {
            if(comp[i] == idc) jury.pb(i);
            else    cat.pb(i);
        }

        if(idc == 1)
            pf("No\n");
        else {
            pf("Yes\n%u %u\n", jury.size(), cat.size());

            for0(i, jury.size()) {
                if(i != 0) pf(" ");
                pf("%lld", jury[i]);
            }
            pn;

            for0(i, cat.size()) {
                if(i != 0) pf(" ");
                pf("%lld", cat[i]);
            }
            pn;
        }

        jury.clear(), cat.clear();
        for1(i, n) {
            comp[i] = vis[i] = 0;
            g[i].clear(), rev[i].clear();
        }
    }

    return 0;
}