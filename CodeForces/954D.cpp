#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> graph[10009];
ll visit[1009], ans = 0, dist[1009][1009];
bool check[1009][1009];
#define pb push_back
struct node {
    ll u;
    ll p;
    node(ll ui, ll pi) {
        u = ui;
        p = pi;
    }
};
int main()
{
    ll n, m, s, t, tot2 = 0;
    ll k;
    cin >> n >> m >> s >> t;
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
        check[u][v] = 1;
        check[v][u] = 1;
    }
    for(ll j = 1; j <= n; j++) {
        queue <node> q;
        q.push(node(j, 0) );
        dist[j][j] = 0;
        check[j][j] = 1;
        memset(visit, 0, sizeof(visit) );
        visit[j] = 1;
        while(!q.empty()) {
            node uv = q.front();
            ll u = uv.u;
            ll cnt = uv.p;
            q.pop();
            for(ll i = 0; i < graph[u].size(); i++) {
                ll nd = graph[u][i];
                if(visit[nd] == 1)
                    continue;
                q.push( node(nd, cnt + 1));
                dist[j][nd] = cnt + 1;
                visit[nd] = 1;
            }
        }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = i + 1; j <= n; j++) {
            if(check[i][j])
                continue;
            ll dist1 = dist[s][i] + 1 + dist[t][j];
            ll dist2 = dist[s][j] + 1 + dist[t][i];
            ll tmp = min(dist1, dist2);
            if(tmp >= dist[s][t]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
