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
ll up[sz], down[sz], val[sz];

void dfs(ll u, ll p)
{
    for(ll &v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u);

        up[u] = max(up[u], up[v]);
        down[u] = max(down[u], down[v]);
    }

    val[u] += up[u];
    val[u] -= down[u];

    ll diff = abs(val[u]);

    if(val[u] > 0) down[u] += diff;
    else up[u] += diff;
}

int main()
{
    ll n;
    cin >> n;

    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) sl(val[i]);

    dfs(1, -1);

    cout << up[1]+down[1] << EL;

    return 0;
}