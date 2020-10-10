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

const ll maxn = 1e5 + 10, tsz = 5*maxn, offset = 1e5;

vector <int> graph[maxn];
int sz[maxn];
bool big[maxn];

int a[maxn], b[maxn];
ll dp[maxn];

struct Line {
    int m; ll c;
} tree[tsz];

int Left[tsz], Right[tsz], idn=1, track[tsz], idt=0;
bool exist[tsz];

inline ll f(Line &line, ll x) {
    return (ll)line.m*(x-offset) + line.c;
}

void add_line(ll lo, ll hi, Line line, ll node)
{
    if(!exist[node]) track[idt++] = node;
    exist[node] = 1;

    if(lo == hi) {
        if(f(line, lo) < f(tree[node], lo))
            tree[node] = line;
        return;
    }

    ll mid = lo+hi>>1;

    bool l = f(line, lo) < f(tree[node], lo);
    bool m = f(line, mid) < f(tree[node], mid);

    if(m) swap(tree[node], line);

    if(l != m) {
        if(!Left[node]) Left[node] = ++idn;
        add_line(lo, mid, line, Left[node]);
    }
    else {
        if(!Right[node]) Right[node] = ++idn;
        add_line(mid+1, hi, line, Right[node]);
    }
}

ll query(ll lo, ll hi, ll p, ll node)
{
    if(lo == hi)
        return f(tree[node], p);

    ll mid = lo+hi>>1, ret = f(tree[node], p);

    if(p <= mid && Left[node]) ret = min(ret, query(lo, mid, p, Left[node]));
    else if(p > mid && Right[node]) ret = min(ret, query(mid+1, hi, p, Right[node]));

    return ret;
}

void szdfs(ll u, ll p)
{
    sz[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        szdfs(nd, u);
        sz[u] += sz[nd];
    }
}

void add(ll u, ll p)
{
    for(auto v: graph[u]) {
        if(v != p && !big[v]) {
            add_line(0, maxn+offset, {b[v], dp[v]}, 1);
            add(v, u);
        }
    }
}

void dfs(ll u, ll p, bool keep)
{
    ll mx = -1, bigChild = -1;
    for(auto v : graph[u])
        if(v != p && sz[v] > mx)
            mx = sz[v], bigChild = v;

    for(auto v : graph[u])
        if(v != p && v != bigChild)
            dfs(v, u, 0);  /// run a dfs on small childs and clear them

    if(bigChild != -1) {
        dfs(bigChild, u, 1);
        big[bigChild] = 1;  /// bigChild marked as big and not cleared
    }

    add(u, p);
    ///now you have the data of vertices in subtree of vertex v. You can answer the queries easily.

    if(graph[u].size() == 1 && u != 1) dp[u] = 0;
    else dp[u] = query(0, maxn+offset, a[u]+offset, 1);

    if(keep) add_line(0, maxn+offset, {b[u], dp[u]}, 1);

    if(bigChild != -1)
        big[bigChild] = 0;

    if(keep == 0) {

        idn = 1;
        while(idt) {
            int node = track[--idt];
            tree[node] = {0, inf};
            exist[node] = Left[node] = Right[node] = 0;
        }
    }
}

int main()
{
    for0(i, tsz) tree[i] = {0, inf};

    ll n;
    cin >> n;

    for1(i, n) si(a[i]);
    for1(i, n) si(b[i]);

    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    szdfs(1, -1);
    dfs(1, -1, 0);

    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%lld", dp[i]);
    }
    pn;

    return 0;
}