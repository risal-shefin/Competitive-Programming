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

const ll sz = 1e5 + 10;
vector <ll> g[sz], got[sz];

struct node {
    ll a, b;
} qry[sz];

struct info {
    ll minNum, cnt;
} tree[4*sz];

ll lazy[4*sz], tim, start[sz], stop[sz], ans[sz];
ll n, m;

void prop(ll lo, ll hi, ll node)
{
    if(lo == hi) return;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;

    lazy[lft] += lazy[node], lazy[rgt] += lazy[node];

    tree[lft].minNum += lazy[node];
    tree[rgt].minNum += lazy[node];

    lazy[node] = 0;
}

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = {0, 1};
        return;
    }

    ll mid = lo+hi>>1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node<<1 | 1);

    tree[node] = {0, tree[node<<1].cnt + tree[node<<1 | 1].cnt};
}

void update(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r) {
        tree[node].minNum += v;
        lazy[node] += v;

        return;
    }
    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi >> 1, lft = node << 1, rgt = node<<1 | 1;
    update(lo, mid, l, r, v, lft);
    update(mid+1, hi, l, r, v, rgt);

    if(tree[lft].minNum < tree[rgt].minNum) tree[node] = tree[lft];
    else if(tree[lft].minNum > tree[rgt].minNum) tree[node] = tree[rgt];
    else    tree[node] = {tree[lft].minNum, tree[lft].cnt + tree[rgt].cnt};
}

void dfs(ll u, ll p)
{
    start[u] = ++tim;
    for(ll &v : g[u]) {
        if(v == p)
            continue;
        dfs(v, u);
    }
    stop[u] = tim;
}

void ans_dfs(ll u, ll p)
{
    for(ll &idx : got[u]) {
        ll a = qry[idx].a, b = qry[idx].b;

        update(1, tim, start[a], stop[a], 1, 1);
        update(1, tim, start[b], stop[b], 1, 1);
    }
    //cout << u << "  " << zero[1] << " " << n << endl;
    if(tree[1].minNum == 0) ans[u] = n - tree[1].cnt - 1;
    else    ans[u] = n-1;

    for(ll &v : g[u]) {
        if(v == p)
            continue;
        ans_dfs(v, u);
    }

    for(ll &idx : got[u]) {
        ll a = qry[idx].a, b = qry[idx].b;

        update(1, tim, start[a], stop[a], -1, 1);
        update(1, tim, start[b], stop[b], -1, 1);
    }
}

int main()
{
    cin >> n >> m;

    for(ll i = 1; i < n; i++) {
        ll u, v;
        si(u), si(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, m) {
        ll a, b;
        si(a), si(b);

        qry[i] = {a, b};

        got[a].pb(i), got[b].pb(i);
    }

    dfs(1, -1);

    build(1, tim, 1);
    ans_dfs(1, -1);

    for1(i, n) {
        if(i != 1)
            pf(" ");

        pf("%d", ans[i] == -1? 0 : ans[i]);
    }
    pn;

    return 0;
}