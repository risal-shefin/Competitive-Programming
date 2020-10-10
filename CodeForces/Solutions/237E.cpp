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
#define inf (1LL << 50)
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

const ll sz = 105;
ll cnt[sz][27], tot[27], lim[sz];

const ll maxnodes = 200;

ll nodes = maxnodes, src, dest;
ll dist[maxnodes], exist[maxnodes];
pll par[maxnodes];

struct Edge
{
    ll to, rev;
    ll f, cap, cost;
};

vector<Edge> g[maxnodes];

void addEdge(ll s, ll t, ll cap, ll cost)
{
    Edge a = {t, g[t].size(), 0, cap, cost};
    Edge b = {s, g[s].size(), 0, 0, -cost};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool spfa()
{
    fill(dist, dist + nodes, inf);
    fill(exist, exist + nodes, 0);

    dist[src] = 0, exist[src] = 1;
    queue <ll> q;
    q.push(src);

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        exist[u] = 0;

        for(ll i = 0; i < g[u].size(); i++) {

            Edge e = g[u][i];

            if(dist[e.to] > dist[u] + e.cost && e.f < e.cap) {

                dist[e.to] = dist[u] + e.cost;
                par[e.to] = mp(u, i);

                if(!exist[e.to]) {
                    q.push(e.to);
                    exist[e.to] = 1;
                }

            }
        }
    }

    return dist[dest] != inf;
}

pll maxFlow(ll _src, ll _dest)
{
    src = _src;
    dest = _dest;
    pll result = mp(0,0);
    while (spfa())
    {
        ll cur = _dest, flow = inf;
        while(cur != _src) {
            ll p = par[cur].first;
            Edge e = g[p][ par[cur].second ];
            flow = min(flow, e.cap - e.f);

            cur = p;
        }
        result.first += flow;

        cur = _dest;
        while(cur != _src) {
            ll p = par[cur].first;
            Edge &e = g[p][ par[cur].second ];

            e.f += flow;
            g[e.to][e.rev].f -= flow;

            result.second += flow * e.cost;

            cur = p;
        }
    }
    return result;
}

int main()
{
    fastio;

    string s;
    cin >> s;
    ll len = s.length();

    for(char &ch : s) tot[ch-'a' + 1]++;

    ll n;
    cin >> n;

    for1(i, n) {
        cin >> s >> lim[i];

        for(char &ch : s) cnt[i][ch-'a' + 1]++;
    }

    for1(i, n) {
        addEdge(0, i, lim[i], i);

        for1(j, 26)
            addEdge(i, n+j, cnt[i][j], 0);
    }

    for1(j, 26) addEdge(n+j, n+30, tot[j], 0);

    pll got = maxFlow(0, n+30);

    if(got.first != len) cout << -1 << EL;
    else cout << got.second << EL;

    return 0;
}