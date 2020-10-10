#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pii pair <int, int>
const int inf = 1e9;
ll mat[2009][2009];
vector <ll> g[2009];
vector <pii> newinp[2009];
ll dist[2009], ans[2009];

struct node {
    ll u, c;
};

bool operator <(node a, node b)

{
    return a.c > b.c;
}

int main()

{
    ll n;
    scanf("%d", &n);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j]) {
                newinp[i].push_back(pii(i, j));
                newinp[j].push_back(pii(i, j));
                g[i].push_back(j);
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(mat[i][i]) {
            ans[i] = 1;
            continue;
        }

        for(ll j = 0; j <= 2005; j++)
            dist[j] = inf;

        for(ll j = 0; j < newinp[i].size(); j++) {
            ll u = newinp[i][j].first, v = newinp[i][j].second;
            if(u == i)
                g[2001].push_back(v);
            else
                g[u].push_back(2001);
        }

        priority_queue <node> pq;
        pq.push({i, 0});
        dist[i] = 0;
        while(!pq.empty()) {
            node u = pq.top();
            pq.pop();

            if(dist[u.u] != u.c)
                continue;
            for(ll v: g[u.u]) {
                if(1 + u.c < dist[v]) {
                    dist[v] = 1 + u.c;
                    pq.push({v, dist[v]});
                }
            }
        }
        if(dist[2001] != inf)
            ans[i] = dist[2001];

        g[2001].clear();
        for(ll j = 0; j < newinp[i].size(); j++) {
            ll u = newinp[i][j].first, v = newinp[i][j].second;
            if(u != i) {
                ll last = g[u].size() - 1;
                while(g[u][last] == 2001 && last >= 0) {
                    g[u].pop_back();
                    last--;
                }
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(ans[i] > 0)
            printf("%d\n", ans[i]);
        else
            printf("NO WAY\n");
    }

    return 0;
