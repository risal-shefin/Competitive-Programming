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

const ll mod = 1000000007, sz = 2009;
ll d, n, way[sz], val[sz];
vector <ll> g[sz];

void dfs(ll mn, ll u, ll p, ll root)
{
    way[u] = 1;

    for(ll &v : g[u]) {
        if(v == p)
            continue;

        if(val[v] == mn && v < root)
            continue;

        if(val[v] >= mn && val[v] <= mn+d) {
            dfs(mn, v, u, root);
            way[u] = (way[u] * (way[v] + 1)) % mod;
        }
    }
}

int main()
{
    cin >> d >> n;

    for1(i, n) sl(val[i]);

    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans = 0;
    for1(i, n) {

        dfs(val[i], i, -1, i);

        ans = (ans + way[i]) % mod;
    }

    cout << ans << EL;

    return 0;
}