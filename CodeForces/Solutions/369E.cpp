// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
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

const ll sz = 1e6 + 10;
vector <ll> rgt[sz];

ll root[sz], per;
const ll psz = 4*sz + 20*(ll)3e5;
ll val[psz], Left[psz], Right[psz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        val[node] = 0;
        return;
    }

    ll mid = lo+hi >> 1;
    Left[node] = ++per, Right[node] = ++per;

    build(lo, mid, Left[node]);
    build(mid+1, hi, Right[node]);

    val[node] = 0;
}

ll update(ll lo, ll hi, ll idx, ll node)
{
    if(lo > idx || hi < idx) return node;

    ll nnode = ++per;
    if(lo == hi) {
        val[nnode] = val[node];
        ++val[nnode];
        return nnode;
    }

    ll mid = lo+hi >> 1;
    Left[nnode] = update(lo, mid, idx, Left[node]);
    Right[nnode] = update(mid+1, hi, idx, Right[node]);

    val[nnode] = val[ Left[nnode] ] + val[ Right[nnode] ];
    return nnode;
}

ll query(ll lo, ll hi, ll l, ll r, ll lnode, ll rnode)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return val[rnode] - val[lnode];

    ll mid = lo+hi >> 1;

    return query(lo, mid, l, r, Left[lnode], Left[rnode])
        +  query(mid+1, hi, l, r, Right[lnode], Right[rnode]);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for1(i, n) {
        ll l, r;
        si(l), si(r);

        rgt[l].pb(r);
    }

    const ll mx = 1e6;
    root[0] = ++per;
    build(1, mx, root[0]);

    for(ll i = 1; i <= 1000000; i++) {
        root[i] = root[i-1];
        for(ll &r : rgt[i])
            root[i] = update(1, mx, r, root[i]);
    }

    while(m--) {
        ll cnt, ans = 0, p, last = 0;
        si(cnt);

        for1(i, cnt) {
            si(p);
            ans += query(1, mx, p, mx, root[last], root[p]);
            last = p;
        }

        pf("%d\n", ans);
    }

    return 0;
}