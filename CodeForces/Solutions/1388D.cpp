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

const ll sz = 2e5 + 10;
vector <ll> g[sz];
vector <int> lst;

ll a[sz], b[sz], ans;
bool vis[sz];

ll dfs(ll u)
{
    for(ll &v: g[u])
        a[u] += dfs(v);

    if(a[u] >= 0) {
        lst.pb(u);
        vis[u] = 1, ans += a[u];
    }

    return max(0LL, a[u]);
}

void dfs2(ll u)
{
    if(!vis[u]) {
        lst.pb(u);
        vis[u] = 1, ans += a[u];
    }

    for(ll &v : g[u]) dfs2(v);
}

int main()
{
    ll n;
    cin >> n;

    for1(i, n) sl(a[i]);

    for1(i, n) {
        sl(b[i]);

        if(b[i] == -1)
            continue;

        g[ b[i] ].pb(i);
    }

    for1(i, n) {
        if(b[i] == -1)
            dfs(i);
    }

    for1(i, n) {
        if(b[i] == -1)
            dfs2(i);
    }

    cout << ans << EL;
    for(ll i = 0; i < lst.size(); i++) {
        if(i != 0) pf(" ");
        pf("%d", lst[i]);
    }
    pn;

    return 0;
}