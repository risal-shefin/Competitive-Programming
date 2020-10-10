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

const ll sz = 1e6 + 10;

struct rec {
    int x, y; ll a;
} ara[sz];

const bool operator <(const rec &a, const rec &b) {
    return a.x < b.x;
}

ll pnt[sz];

struct Line {
    int m; ll c;
} tree[4*sz];
bool exist[4*sz];

inline ll f(Line &line, ll &x) {
    return (ll)line.m*x + line.c;
}

void add(ll lo, ll hi, Line &line, ll node)
{
    exist[node] = 1;

    if(lo == hi) {
        if(f(line, pnt[lo]) > f(tree[node], pnt[lo]))
            tree[node] = line;
        return;
    }

    ll mid = lo+hi >> 1;

    bool left = f(line, pnt[lo]) > f(tree[node], pnt[lo]);
    bool m = f(line, pnt[mid]) > f(tree[node], pnt[mid]);

    if(m) swap(line, tree[node]);

    if(left != m) add(lo, mid, line, node<<1);
    else add(mid+1, hi, line, node<<1|1);
}

ll query(ll lo, ll hi, ll &idx, ll node)
{
    if(lo == hi)
        return f(tree[node], pnt[idx]);

    ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

    if(idx <= mid && exist[node<<1]) ret = max(ret, query(lo, mid, idx, node<<1));
    else if(idx > mid && exist[(node<<1|1)]) ret = max(ret, query(mid+1, hi, idx, node<<1 | 1));

    return ret;
}

int main()
{
    Line line;

    ll n;
    cin >> n;

    for1(i, n) {
        scanf("%d %d %lld", &ara[i].x, &ara[i].y, &ara[i].a);
    }

    sort(ara+1, ara+n+1);
    for1(i, n) pnt[i] = -ara[i].y;

    ll ans = 0;
    for1(i, n) {

        ll got = (ll)ara[i].x * ara[i].y - ara[i].a + query(1, n, i, 1);

        line.m = ara[i].x, line.c = got;
        add(1, n, line, 1);

        ans = max(ans, got);
    }

    cout << ans << EL;

    return 0;
}