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

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

const ll sz = 1e5 + 10;

bool vis[sz];
vector <ll> g[sz], comp;

ll siz;

void dfs(ll u)
{
    vis[u] = 1, siz++;

    for(ll &v : g[u]) {
        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) {
        if(vis[i])
            continue;

        siz = 0;
        dfs(i);

        comp.pb(siz);
    }

    if(comp.size() == 1) {
        cout << (1%k) << endl;
        return 0;
    }

    ll way = fastPow(n, comp.size()-2, k);

    for(ll &sz : comp) way = (way * sz) % k;

    cout << way << EL;

    return 0;
}