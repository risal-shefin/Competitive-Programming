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

const ll sz = 1e5 + 10, lim = 20;
ll tree[20][4*sz], lazy[4*sz], ara[sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        for0(i, lim)
            tree[i][node] = (ara[lo] >> i) & 1;

        return;
    }

    ll mid = lo+hi >> 1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node<<1 | 1);

    for0(i, lim)
        tree[i][node] = tree[i][(node << 1)] + tree[i][(node<<1 | 1)];
}

void prop(ll lo, ll hi, ll node)
{
    if(lo==hi) return;

    ll mid = lo+hi >> 1, l = node<<1, r = node<<1 | 1;

    lazy[l] ^= lazy[node], lazy[r] ^= lazy[node];

    for0(i, lim) {
        bool bt = (lazy[node] >> i) & 1;
        if(bt) {
            tree[i][l] = (mid-lo+1) - tree[i][l];
            tree[i][r] = (hi - mid) - tree[i][r];
        }
    }
    lazy[node] = 0;
}

void update(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r) {
        for0(i, lim) {
            bool bt = (v >> i) & 1;
            if(bt) tree[i][node] = (hi-lo+1) - tree[i][node];
        }
        lazy[node] ^= v;
        return;
    }
    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi >> 1;
    update(lo, mid, l, r, v, node<<1);
    update(mid+1, hi, l, r, v, node<<1 | 1);

    for0(i, lim)
        tree[i][node] = tree[i][(node << 1)] + tree[i][(node<<1 | 1)];
}

ll query(ll lo, ll hi, ll l, ll r, ll bt, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tree[bt][node];

    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi >> 1;
    return query(lo, mid, l, r, bt, node<<1)
        +  query(mid+1, hi, l, r, bt, node<<1 | 1);
}

int main()
{
    ll n;
    cin >> n;
    for1(i, n) sl(ara[i]);

    build(1, n, 1);

    ll q;
    cin >> q;
    while(q--) {
        ll op, l, r, x;
        sl(op), sl(l), sl(r);

        if(op == 1) {
            ll sum = 0;
            for0(i, lim) {
                ll cnt = query(1, n, l, r, i, 1);
                sum += cnt * (1LL << i);
            }
            pf("%lld\n", sum);
        }
        else {
            sl(x);
            update(1, n, l, r, x, 1);
        }
    }

    return 0;
}