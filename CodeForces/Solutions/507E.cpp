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

const ll sz = 1e5 + 10;
vector <pll> g[sz], par[sz];
unordered_set <int> path[sz];
ll lev[sz], dp[sz], togo[sz];

struct info {
    ll u, v, z;
};
vector <info> ans;

ll solve(ll u)
{
    if(u == 1) return 0;
    ll &ret = dp[u];
    if(ret != -1)
        return ret;

    ll rt = inf;
    for(pll &v : par[u]) {
        ll nd = v.first, typ = v.second;
        ll got = (typ == 0) + solve(nd);

        if(got < rt) {
            rt = got;
            togo[u] = nd;
        }
    }

    return ret = rt;
}

int main()
{
    ll n, m;
    sl(n), sl(m);

    for1(i, m) {
        ll u, v, z;
        sl(u), sl(v), sl(z);

        g[u].pb({v, z}), g[v].pb({u, z});
    }

    for1(i, n) lev[i] = inf;

    queue <int> q;
    q.push(1);
    lev[1] = 0;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(pll &v: g[u]) {
            ll nd = v.first, typ = v.second;

            if(lev[u] + 1 < lev[nd]) {
                lev[nd] = lev[u] + 1;
                par[nd].pb({u, typ});
                q.push(nd);
            }
            else if(lev[u] + 1 == lev[nd])
                par[nd].pb({u, typ});
        }
    }

    ms(dp, -1);
    solve(n);

    ll stop = n;
    while(stop != 1) {
        path[stop].insert( togo[stop] );
        path[ togo[stop] ].insert(stop);

        stop = togo[stop];
    }

    for1(i, n) {
        for(pll &v : g[i]) {
            ll nd = v.first, typ = v.second;
            if(nd < i) continue;

            auto it = path[i].find(nd);
            if(it == path[i].end() && typ == 1)
               ans.pb({i, nd, 0});
            else if(it != path[i].end() && typ == 0)
                ans.pb({i, nd, 1});
        }
    }

    cout << ans.size() << EL;
    for(info &fo : ans)
        pf("%lld %lld %lld\n", fo.u, fo.v, fo.z);

    return 0;
}