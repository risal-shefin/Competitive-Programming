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

const ll sz = 2e5 + 10, psz = 4*sz + sz*18;

struct info {
    ll city, tim, id;
    bool typ;
} ara[2*sz];

const bool operator <(const info &a, const info &b) {
    if(a.tim != b.tim)
        return a.tim < b.tim;
    return a.typ < b.typ;
}

ll dp[sz];

struct Line {
    ll m, c;
} tree[psz];

inline ll f(Line &line, ll x) {
    return line.m*x + line.c;
}

int Left[psz], Right[psz], root[psz], idn, pnt[sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = {0, inf};
        return;
    }

    int mid = lo+hi >> 1;
    Left[node] = ++idn, Right[node] = ++idn;

    build(lo, mid, Left[node]);
    build(mid+1, hi, Right[node]);

    tree[node] = {0, inf};
}

int add(ll lo, ll hi, Line line, ll node)
{
    ll nnode = ++idn;

    if(lo == hi) {
        tree[nnode] = tree[node];

        if(f(line, pnt[lo]) < f(tree[nnode], pnt[lo]))
            tree[nnode] = line;

        return nnode;
    }

    tree[nnode] = tree[node], Left[nnode] = Left[node], Right[nnode] = Right[node];

    int mid = lo+hi >> 1;

    bool l = f(line, pnt[lo]) < f(tree[nnode], pnt[lo]);
    bool m = f(line, pnt[mid]) < f(tree[nnode], pnt[mid]);

    if(m) swap(tree[nnode], line);

    if(l != m) Left[nnode] = add(lo, mid, line, Left[nnode]);
    else Right[nnode] = add(mid+1, hi, line, Right[nnode]);

    return nnode;
}

ll query(ll lo, ll hi, ll idx, ll node)
{
    if(lo == hi)
        return f(tree[node], pnt[idx]);

    ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

    if(idx <= mid) ret = min(ret, query(lo, mid, idx, Left[node]));
    else ret = min(ret, query(mid+1, hi, idx, Right[node]));

    return ret;
}

inline ll sq(ll num) {return num*num;}

int main()
{
    ll n, m;
    cin >> n >> m;

    ll idx = 0;
    for1(i, m) {
        ll a, b, s, e;
        scanf("%lld %lld %lld %lld", &a, &b, &s, &e);

        ara[++idx] = {a, s, i, 0};
        ara[++idx] = {b, e, i, 1};
    }
    sort(ara+1, ara+idx+1);

    ll ptr = 0;
    for1(i, idx) if(ara[i].typ == 0) pnt[++ptr] = ara[i].tim;

    root[1] = ++idn;
    build(1, m, root[1]);

    for1(i, m) root[i] = root[1];

    root[1] = add(1, m, {0, 0}, root[1]);

    ll ans = inf, pos = 0;

    for1(i, idx) {
        if(ara[i].typ == 0) {
            dp[ ara[i].id ] = query(1, m, ++pos, root[ ara[i].city ]) + sq(ara[i].tim);
        }
        else {
            root[ ara[i].city ] = add(1, m, {-2*ara[i].tim, sq(ara[i].tim) + dp[ ara[i].id ]}, root[ ara[i].city ]);

            if(ara[i].city == n) ans = min(ans, dp[ ara[i].id ]);
        }
    }

    cout << ans << EL;

    return 0;
}