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
#define inf (1LL << 60)
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

const ll sz = 1e5 + 10;
ll a[sz], b[sz], dp[sz];

struct Line {
    ll m, c;

    inline ll f(ll x) {return m*x + c;}
} tree[4*sz];
bool exist[4*sz];

void add(ll lo, ll hi, Line &line, ll node)
{
    exist[node] = 1;

    if(lo == hi) {
        if(line.f(a[lo]) < tree[node].f(a[lo]))
            tree[node] = line;

        return;
    }

    ll mid = lo+hi >> 1;
    bool left = line.f(a[lo]) < tree[node].f(a[lo]);
    bool m = line.f(a[mid]) < tree[node].f(a[mid]);

    if(m) swap(tree[node], line);   // new line gives the best answer in mid point

    // left != m means line intersection between new line and
    // tree[node]'s line is occurring in the left side of mid point
    if(left != m) add(lo, mid, line, node<<1);
    else add(mid+1, hi, line, node<<1|1);
}

ll query(ll lo, ll hi, ll idx, ll node)
{
    if(lo == hi)
        return tree[node].f(a[idx]);

    ll mid = lo+hi >> 1, ret = tree[node].f(a[idx]);

    if(idx <= mid && exist[node<<1]) ret = min(ret, query(lo, mid, idx, node<<1));
    else if(idx > mid && exist[node<<1|1]) ret = min(ret, query(mid+1, hi, idx, node<<1|1));

    return ret;
}

int main()
{
    ll n;
    cin >> n;

    for1(i, n) sl(a[i]);
    for1(i, n) sl(b[i]);

    for0(i, 4*sz) tree[i] = {0, inf};

    dp[1] = 0;
    Line line = {b[1], dp[1]};
    add(1, n, line, 1);

    for(ll i = 2; i <= n; i++) {
        dp[i] = query(1, n, i, 1);

        line = {b[i], dp[i]};
        add(1, n, line, 1);
    }

    cout << dp[n] << EL;

    return 0;
}