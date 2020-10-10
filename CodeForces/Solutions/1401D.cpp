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
#define inf (1LL << 61)
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

const ll sz = 1e5 + 10, msz = 6e4 + 10, mod = 1e9 + 7;
vector <ll> g[sz];

struct edge {
    ll u, v, cnt, val;
} ed[sz];

const bool operator <(const edge &a, const edge &b) {
    return a.cnt > b.cnt;
}

ll p[msz], sub[sz];

void dfs(ll u, ll p)
{
    sub[u] = 1;
    for(ll &v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u);
        sub[u] += sub[v];
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n; sl(n);

        for(ll i = 1; i < n; i++) {
            ll u, v;
            sl(u), sl(v);

            ed[i] = {u, v};

            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(1, -1);

        for(ll i = 1; i < n; i++) {
            ll sb = min(sub[ ed[i].u ], sub[ ed[i].v ]);

            ll rest = n - sb;
            ed[i].cnt = sb * rest, ed[i].val = 1;
        }
        sort(ed+1, ed+n);

        ll m; sl(m);
        for1(i, m) sl(p[i]);

        sort(p+1, p+m+1, greater<ll>());

        ll ptr = 1;
        while(m-ptr+1 > n-1)
            ed[1].val = (ed[1].val * p[ptr++]) % mod;

        for(ll i = 1; i < n; i++, ptr++)
            ed[i].val = (ed[i].val * p[ptr]) % mod;

        ll ans = 0;
        for(ll i = 1; i <= min(m, n-1); i++) {
            ed[i].cnt %= mod;
            ll now = (ed[i].cnt * ed[i].val) % mod;

            ans = (ans + now) % mod;
        }

        for(ll i = m+1; i < n; i++)
            ans = (ans + ed[i].cnt) % mod;

        pf("%lld\n", ans);

        for1(i, n) g[i].clear();
    }

    return 0;
}