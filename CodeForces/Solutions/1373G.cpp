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
unordered_set <int> pawn[sz];
multiset <int> lst;

ll tree[4* 2*sz], lazy[4* 2*sz];

void prop(ll lo, ll hi, ll node)
{
    ll mid = lo+hi >> 1, l = node<<1, r = node<<1|1;

    tree[l] += lazy[node], tree[r] += lazy[node];
    lazy[l] += lazy[node], lazy[r] += lazy[node];

    lazy[node] = 0;
}

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = lo;
        return;
    }

    ll mid = lo+hi>>1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node<<1|1);

    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

void update(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r) {
        tree[node] += v;
        lazy[node] += v;
        return;
    }
    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi>>1;
    update(lo, mid, l, r, v, node<<1);
    update(mid+1, hi, l, r, v, node<<1 | 1);

    tree[node] = max(tree[node<<1], tree[node<<1 | 1]);
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return -inf;
    if(lo >= l && hi <= r)
        return tree[node];

    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi >> 1;
    return max(query(lo, mid, l, r, node<<1),
           query(mid+1, hi, l, r, node<<1 | 1));
}

int main()
{
    ll n, k, m, mxr = 4e5;
    cin >> n >> k >> m;

    build(1, mxr, 1);

    for1(i, m) {
        ll x, y;
        sl(x), sl(y);

        ll diff = abs(x - k), ky = y + diff;

        if(pawn[x].find(y) != pawn[x].end()) {
            pawn[x].erase(y);
            lst.erase(lst.find(ky));
            update(1, mxr, 1, ky, -1, 1);
        }
        else {
            pawn[x].insert(y);
            lst.insert(ky);
            update(1, mxr, 1, ky, 1, 1);
        }

        ll leastRow = n;
        if(!lst.empty()) leastRow = query(1, mxr, 1, *lst.rbegin(), 1) - 1;

        pf("%lld\n", max(0LL, leastRow - n));
    }

    return 0;
}