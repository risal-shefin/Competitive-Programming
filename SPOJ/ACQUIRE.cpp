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

const ll sz = 5e4 + 10;

pii ara[sz], lst[sz];
ll pnt[sz], dp[sz];

struct Line {
    ll m, c;
} tree[4*sz];

bool exist[4*sz];

inline ll f(Line &line, ll x) {
    return line.m*x + line.c;
}

void add(ll lo, ll hi, Line line, ll node)
{
    exist[node] = 1;

    if(lo == hi) {
        if(f(line, pnt[lo]) < f(tree[node], pnt[lo]))
            tree[node] = line;
        return;
    }

    ll mid = lo+hi >> 1;

    bool l = f(line, pnt[lo]) < f(tree[node], pnt[lo]);
    bool m = f(line, pnt[mid]) < f(tree[node], pnt[mid]);

    if(m) swap(tree[node], line);

    if(l != m) add(lo, mid, line, node<<1);
    else add(mid +1, hi, line, node<<1|1);
}

ll query(ll lo, ll hi, ll idx, ll node)
{
    if(lo == hi)
        return f(tree[node], pnt[idx]);

    ll mid = lo+hi >> 1, ret = f(tree[node], pnt[idx]);

    if(idx <= mid && exist[node<<1]) ret = min(ret, query(lo, mid, idx, node<<1));
    else if(idx > mid && exist[node<<1|1]) ret = min(ret, query(mid+1, hi, idx, node<<1|1));

    return ret;
}

int main()
{
    ll n;
    cin >> n;

    for1(i, n) {
        si(ara[i].first), si(ara[i].second);
    }
    sort(ara+1, ara+n+1);

    ll mxw = 0, idx = 0;
    rep1(i, n) {
        if(ara[i].second > mxw)
            lst[++idx] = ara[i];

        mxw = max(mxw, (ll)ara[i].second);
    }
    reverse(lst+1, lst+idx+1);

    for1(i, idx) pnt[i] = lst[i].first;
    for0(i, 4*sz) tree[i] = {0, inf};

    for1(i, idx) {

        add(1, idx, {lst[i].second, dp[i-1]}, 1);

        dp[i] = query(1, idx, i, 1);
    }

    cout << dp[idx] << EL;

    return 0;
