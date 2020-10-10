#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector <ll> graph[100009], cost[100009];
ll dist[100009];

void dfs(ll nd, ll p, ll mx)

{
    for(ll i = 0; i < graph[nd].size(); i++) {
        if(graph[nd][i] == p)
            continue;
        ll u = graph[nd][i];
        ll cst = cost[nd][i];
        cst = max(cst, mx);

        if(dist[u] > cst) {
            dist[u] = cst;
            dfs(u, nd, cst);
        }
    }

    return;
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        for(ll i = 1; i <= 100005; i++)
            dist[i] = 1e18;

        ll n, m, u, v, c;
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= m; i++) {
            scanf("%lld %lld %lld", &u, &v, &c);

            graph[u].pb(v);
            graph[v].pb(u);

            cost[u].pb(c);
            cost[v].pb(c);
        }

        dist[1] = 0;
        dfs(1, -1 , 0);

        ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            cost[i].clear();
            graph[i].clear();
            ans = max(ans, dist[i]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}