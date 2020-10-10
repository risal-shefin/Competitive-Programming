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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;
vector <ll> g[sz];
ll far, farNode, lev1[sz], lev2[sz], node1, node2 = -1, mx[sz];

void dfs(ll u, ll p, ll lv)
{
    if(lv > far)
        far = lv, farNode = u;

    if(node2 != -1)     lev2[u] = lv;
    else                lev1[u] = lv;

    for(ll v : g[u]) {
        if(v == p)
            continue;

        dfs(v, u, lv+1);
    }
}

void dfs2(ll u, ll p, ll lv)
{
    mx[u] = max(mx[u], lv);
    for(ll v : g[u]) {
        if(v == p)
            continue;

        if(lev1[v] + lev2[v] == far)
            dfs2(v, u, lv);
        else
            dfs2(v, u, lv+1);
    }
}

int main()

{
    ll n;
    sl(n);
    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1, 0);
    node1 = farNode;

    far = 0;
    dfs(node1, -1, 0);
    node2 = farNode;

    dfs(node2, -1, 0);

    dfs2(node1, -1, 0);
    dfs2(node2, -1, 0);

    ll mxd = -1, node3;
    for1(i, n) {
        if(i == node1 || i == node2)
            continue;

        if(mx[i] > mxd) {
            mxd = mx[i];
            node3 = i;
        }
    }

    cout << far + mxd << endl;
    cout << node1 << " " << node2 << " " << node3 << endl;

    return 0;
}