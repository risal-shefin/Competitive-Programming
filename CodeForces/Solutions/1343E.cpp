#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const ll sz = 2e5 + 10;
vector <ll> g[sz];

ll lev[3][sz], cst[sz], csum[sz];

void bfs(ll op, ll src)
{
    lev[op][src] = 0;
    queue <ll> q;
    q.push(src);

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll &v: g[u]) {
            if(lev[op][v] != -1)
                continue;

            lev[op][v] = lev[op][u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, a, b, c, u , v;
        scanf("%lld %lld %lld %lld %lld", &n, &m, &a, &b, &c);

        for1(i, m) sl(cst[i]), csum[i] = 0;
        sort(cst+1, cst+m+1);
        for1(i, m) csum[i] += csum[i-1] + cst[i];

        for1(i, m) {
            sl(u), sl(v);
            g[u].pb(v);
            g[v].pb(u);
        }

        for1(i, n) lev[0][i] = lev[1][i] = lev[2][i] = -1;

        bfs(0, a);
        bfs(1, b);
        bfs(2, c);

        ll ans = inf;
        for1(i, n) {
            ll da = lev[0][i], db = lev[1][i], dc = lev[2][i];
            ll tot = da + db + dc;
            if(tot > m) continue;
            ans = min(ans, csum[tot] + csum[db]);
        }

        pf("%lld\n", ans);

        for1(i, n) g[i].clear();
    }

    return 0;
}