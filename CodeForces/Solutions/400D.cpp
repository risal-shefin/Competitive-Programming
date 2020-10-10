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

const ll sz = 1e5 + 10, tsz = 505;
vector <ll> g[sz];
ll cst[tsz][tsz], typ[sz], mark[sz];

void dfs(ll u, ll tim)
{
    mark[u] = tim;
    for(ll &v : g[u])
        if(!mark[v])
            dfs(v, tim);
}

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll prv = 0;
    for1(i, k) {
        ll c; sl(c);

        for(ll j = prv+1; j <= prv+c; j++)
            typ[j] = i;

        prv += c;
    }

    for1(i, k)
        for1(j, k)
            cst[i][j] = (i==j)? 0LL : inf;

    for1(i, m) {
        ll u, v, c;
        sl(u), sl(v), sl(c);

        ll t1 = typ[u], t2 = typ[v];
        cst[t1][t2] = cst[t2][t1] = min(cst[t1][t2], c);

        if(c == 0) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    ll tim = 0;
    for1(i, n) {
        if(!mark[i])
            dfs(i, ++tim);
    }

    bool ok = 1;
    for1(i, (n-1)) {
        if(typ[i] != typ[i+1])
            continue;

        if(mark[i] != mark[i+1]) {
            ok = 0;
            break;
        }
    }

    if(!ok) {
        cout << "No" << EL;
        return 0;
    }

    cout << "Yes" << EL;

    for1(w, k)
        for1(u, k)
            for1(v, k)
                cst[u][v] = min(cst[u][v], cst[u][w] + cst[w][v]);


    for1(i, k) {
        for1(j, k) {
            if(j != 1) pf(" ");

            pf("%lld", cst[i][j]==inf? -1LL : cst[i][j]);
        }
        pn;
    }

    return 0;
}