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

const ll sz = 3e5 + 10;

ll ara[sz], n;

struct info {
    ll g, mn;
} tree[4*sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = {ara[lo], ara[lo]};
        return;
    }

    ll mid = lo+hi>>1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node<<1|1);

    tree[node].g = __gcd(tree[node<<1].g, tree[node<<1|1].g);
    tree[node].mn = min(tree[node<<1].mn, tree[node<<1|1].mn);
}

info query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return {0, (int)1e9};
    if(lo >= l && hi <= r)
        return tree[node];

    ll mid = lo+hi >> 1;
    info p1 = query(lo, mid, l, r, node<<1);
    info p2 = query(mid+1, hi, l, r, node<<1|1);

    return {__gcd(p1.g, p2.g), min(p1.mn, p2.mn)};
}

vector <ll> lst;

inline bool solve(ll len)
{
    bool ok = 0;
    for(ll i = 1; i+len <= n; i++) {
        info got = query(1, n, i, i+len, 1);

        if(got.g == got.mn) {
            if(!ok) lst.clear();
            lst.pb(i);
            ok = 1;
        }
    }
    return ok==1;
}

int main()
{
    cin >> n;
    for1(i, n) si(ara[i]);

    build(1, n, 1);

    ll ans = 0, lo = 0, hi = n-1;
    while(lo <= hi) {
        ll mid = lo+hi >> 1;

        if(solve(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << lst.size() << " " << ans << EL;
    for(ll &el : lst) pf("%d ", el);
    pn;

    return 0;
}