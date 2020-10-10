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

const ll sz = 1e5 + 10;

struct node {
    ll v, c;
};
const bool operator <(const node &a, const node &b) {
    return a.c > b.c;
}

vector <node> g[sz];
vector <pll> lst[sz];
ll dist[sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) {
        ll u, v, c;
        sl(u), sl(v), sl(c);

        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    for1(i, n) {
        ll num; sl(num);

        ll last;
        for1(j, num) {
            ll per; sl(per);
            lst[i].pb(mp(per, -1));

            last = lst[i].back().first+1;
        }

        for(ll j = num-1; j >= 0; j--) {

            if(j == num-1 || lst[i][j].first+1 == lst[i][j+1].first)
                lst[i][j].second = last;
            else {
                lst[i][j].second = lst[i][j].first + 1;
                last = lst[i][j].second;
            }
        }

        dist[i] = inf;
    }

    priority_queue <node> pq;

    ll start = 0;
    if(!lst[1].empty() && lst[1][0].first == 0)
        start = lst[1][0].second;

    pq.push({1, start});
    dist[1] = start;

    while(!pq.empty()) {
        node u = pq.top();
        pq.pop();

        if(u.c != dist[u.v])
            continue;

        for(node &nd: g[u.v]) {

            if(dist[u.v] + nd.c < dist[nd.v]) {

                ll tim = dist[u.v] + nd.c;

                if(nd.v != n) {
                    ll pos = lower_bound(all(lst[nd.v]), mp(tim, 0LL)) - lst[nd.v].begin();

                    if(pos != lst[nd.v].size() && lst[nd.v][pos].first == tim)
                        tim = lst[nd.v][pos].second;
                }

                if(tim >= dist[nd.v])
                    continue;

                dist[nd.v] = tim;
                pq.push({nd.v, tim});
            }
        }
    }

    if(dist[n] != inf) cout << dist[n] << EL;
    else    cout << -1 << EL;

    return 0;
}