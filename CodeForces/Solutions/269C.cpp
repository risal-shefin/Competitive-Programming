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
#define inf (1LL << 61)
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

struct node {
    ll v, flow, id, dir;
};
vector <node> g[sz];
ll flow[sz];
bool dir[sz], vis[sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) {
        ll u, v, c;
        sl(u), sl(v), sl(c);

        g[u].pb({v, c, i, 0});
        g[v].pb({u, c, i, 1});

        flow[u] += c, flow[v] += c;
    }

    for(ll i = 2; i < n; i++) flow[i] /= 2;

    queue <ll> q;
    q.push(1);

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(node &nd : g[u]) {

            if(vis[nd.id])
                continue;

            vis[nd.id] = 1, dir[nd.id] = nd.dir;
            flow[nd.v] -= nd.flow;

            if(nd.v != n && flow[nd.v] == 0)
                q.push(nd.v);
        }
    }

    for1(i, m) pf("%d\n", (int)dir[i]);

    return 0;
}