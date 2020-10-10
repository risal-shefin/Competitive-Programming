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

const ll sz = 2e5 + 10;
ll ara[sz], tim, start[sz], stop[sz], lvl[sz];
vector <ll> g[sz];

void dfs(ll u, ll p)
{
    start[u] = ++tim, lvl[u] = lvl[p] + 1;
    for(ll &v : g[u]) {
        if(v == p)
            continue;
        dfs(v, u);
    }
    stop[u] = tim;
}

struct Seg {
    ll tree[4*sz], lazy[4*sz];

    void prop(ll lo, ll hi, ll node) {
        if(lo == hi) return;

        tree[node<<1] += lazy[node];
        tree[node<<1|1] += lazy[node];

        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];

        lazy[node] = 0;
    }

    void update(ll lo, ll hi, ll l, ll r, ll v, ll node) {
        if(lazy[node]) prop(lo, hi, node);

        if(lo > r || hi < l) return;

        if(lo >= l && hi <= r) {
            tree[node] += v;
            lazy[node] += v;
            return;
        }

        ll mid = (lo+hi) >> 1;
        update(lo, mid, l, r, v, node<<1);
        update(mid+1, hi, l, r, v, node<<1 | 1);
    }

    ll query(ll lo, ll hi, ll idx, ll node) {
        if(lazy[node]) prop(lo, hi, node);

        if(lo > idx || hi < idx) return 0;
        if(lo == hi) return tree[node];

        ll mid = (lo+hi) >> 1;
        return query(lo, mid, idx, node<<1)
            +  query(mid+1, hi, idx, node<<1 | 1);
    }
} segOdd, segEven;

int main()
{
    ll n, m;
    cin >> n >> m;
    for1(i, n) sl(ara[i]);

    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    while(m--) {
        ll op, x, val;
        sl(op);

        if(op == 1) {
            sl(x), sl(val);

            if(lvl[x] & 1) segOdd.update(1, tim, start[x], stop[x], val, 1);
            else    segEven.update(1, tim, start[x], stop[x], val, 1);
        }
        else {
            sl(x);

            ll odd = segOdd.query(1, tim, start[x], 1);
            ll even = segEven.query(1, tim, start[x], 1);

            ll ans = ara[x];
            if(lvl[x] & 1) ans = ans + odd - even;
            else     ans = ans + even - odd;

            pf("%lld\n", ans);
        }
    }

    return 0;
}