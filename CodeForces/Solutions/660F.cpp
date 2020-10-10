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

const ll sz = 2e5 + 10, MAX_N = 2e12 + 10, offset = 2e12, psz = sz*42;
ll pre[sz], mpre[sz], a[sz];

struct Line {
    ll m, c;
} tree[psz];

int Left[psz], Right[psz], idp = 1;

inline ll f(Line line, ll x) {
    return line.m*(x-offset) + line.c;
}

void add(ll lo, ll hi, Line line, ll node)
{
    if(lo == hi) {
        if(f(line, lo) > f(tree[node], lo))
            tree[node] = line;
        return;
    }

    ll mid = lo+hi >> 1LL;

    bool left = f(line, lo) > f(tree[node], lo);
    bool m = f(line, mid) > f(tree[node], mid);

    if(m) swap(tree[node], line);

    if(left != m) {
        if(!Left[node]) Left[node] = ++idp;
        add(lo, mid, line, Left[node]);
    }
    else {
        if(!Right[node]) Right[node] = ++idp;
        add(mid+1, hi, line, Right[node]);
    }
}

ll query(ll lo, ll hi, ll x, ll node)
{
    if(lo == hi)
        return f(tree[node], x);

    ll mid = lo+hi >> 1LL, ret = f(tree[node], x);

    if(x <= mid && Left[node])
        ret = max(ret, query(lo, mid, x, Left[node]));
    else if(x > mid && Right[node])
        ret = max(ret, query(mid+1, hi, x, Right[node]));

    return ret;
}

int main()
{
    for0(i, psz) tree[i] = {0, -inf};

    ll n, ans = 0;
    cin >> n;
    for1(i, n) {
        sl(a[i]);

        pre[i] = pre[i-1] + a[i];
        mpre[i] = mpre[i-1] + (i * a[i]);

        Line line = {-(i-1), (i-1)*pre[i-1] - mpre[i-1]};

        add(0, MAX_N+offset, line, 1);
        ans = max(ans, mpre[i] + query(0, MAX_N+offset, pre[i]+offset, 1));
    }

    cout << ans << EL;

    return 0;
}