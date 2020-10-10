#include <bits/stdc++.h>
using namespace std;

#define ll int
#define inf 1000000000
struct node {
    ll u, c;
};

bool operator <(node a, node b) {
    return a.c > b.c;
}

vector <node> g[500009];
priority_queue <node> pq;
ll dist[500009];

int main()

{
    ll n, m, q, u, v, c, mx, cnt;
    node tmp, nd;
    scanf("%d %d %d", &n, &m, &q);

    for(ll i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    while(q--) {
        scanf("%d", &u);

        for(ll i = 0; i < n; i++)
            dist[i] = inf;

        pq.push({u, 0});
        dist[u] = 0;
        while(!pq.empty()) {
            tmp = pq.top();
            pq.pop();

            if(dist[tmp.u] != tmp.c)
                continue;

            for(ll i = 0; i < g[tmp.u].size(); i++) {
                nd = g[tmp.u][i];
                if(tmp.c + nd.c < dist[nd.u]) {
                    dist[nd.u] = tmp.c + nd.c;
                    pq.push({nd.u, dist[nd.u]});
                }
            }
        }

        mx = 0, cnt = 0;
        for(ll i = 0; i < n; i++) {
            if(dist[i] == inf)
                continue;
            if(dist[i] > mx) {
                mx = dist[i];
                cnt = 1;
            }
            else if(dist[i] == mx)
                cnt++;
        }

        printf("%d %d\n", mx, cnt);
    }

    return 0;
