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

const ll sz = 1e5 + 10;
vector <ll> g[sz];
ll pep[sz], h[sz];
bool ok;

pll dfs(ll u, ll par)
{
    ll good = 0, bad = 0;

    for(ll &v : g[u]) {
        if(v == par)
            continue;

        pll got = dfs(v, u);

        good += got.first, bad += got.second;
    }

    ll diff = good - bad;
    ll need = h[u] - diff, p = pep[u];

    if(need > 0) {
        ll mn = min(need / 2, bad);
        bad -= mn, good += mn;
        need -= (mn*2);
    }

    ll sum = need+p;
    if(sum & 1) {
        ok = 0;
        return mp(-1,-1);
    }

    ll g = sum / 2, b = p - g;
    if(g < 0 || b < 0) {
        //cout << u << " " << good << " " << bad << endl;
        ok = 0;
        return mp(-1, -1);
    }

    good += g, bad += b;
    return mp(good, bad);
}

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll n, m;
        sl(n), sl(m);

        for1(i, n) sl(pep[i]);
        for1(i, n) sl(h[i]);

        for(ll i = 1; i < n; i++) {
            ll u, v;
            sl(u), sl(v);

            g[u].pb(v);
            g[v].pb(u);
        }

        ok = 1;
        dfs(1, -1);

        if(ok) pf("YES\n");
        else pf("NO\n");

        for1(i, n) g[i].clear();
    }

    return 0;
}