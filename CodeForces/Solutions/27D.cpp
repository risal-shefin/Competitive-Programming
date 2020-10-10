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

const ll sz = 105;

struct node {
    ll l, r;
} ara[sz];

ll n, m, col[sz];

vector <ll> g[sz];

inline bool inter(node a, node b) {

    if(a.l > b.l) swap(a, b);

    if(b.l > a.l && b.l < a.r && b.r > a.r)
        return 1;

    return 0;
}

bool bicolor(ll nd)
{
    queue <ll> q;
    q.push(nd);
    col[nd] = 1;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll &v : g[u]) {
            if(col[v] == col[u])
                return 0;

            if(!col[v]) {
                col[v] = (col[u]==1) ? 2 : 1;
                q.push(v);
            }
        }
    }

    return 1;
}

int main()
{
    cin >> n >> m;

    for1(i, m) {
        sl(ara[i].l), sl(ara[i].r);

        if(ara[i].l > ara[i].r) swap(ara[i].l, ara[i].r);
    }

    for1(i, m) {

        for(ll j = i+1; j <= m; j++) {

            if( inter(ara[i], ara[j]) )
                g[i].pb(j), g[j].pb(i);
        }
    }

    bool ok = 1;
    for1(i, m) {
        if(col[i])
            continue;

        ok &= bicolor(i);
    }

    if(!ok) cout << "Impossible" << EL;
    else {
        for1(i, m) pf("%c", col[i]==1? 'i' : 'o');
        pn;
    }

    return 0;
}