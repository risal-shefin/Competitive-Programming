#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1000000000000000000

vector <ll> graph[200009], cost[200009];
ll tck[200009], dist[200009];

struct node {
    ll p;
    ll cost;
    node(ll point, ll c) {
        p = point;
        cost = c;
    }
};

bool operator <(node a, node b)

{
    return a.cost > b.cost;
}

int main()

{
    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= m; i++) {
        ll u, v, w;
        scanf("%I64d %I64d %I64d", &u, &v, &w);
        graph[u].push_back(v);
        graph[v].push_back(u);

        cost[u].push_back(2 * w);
        cost[v].push_back(2 * w);
    }

    priority_queue <node> pq;
    for(ll i = 1; i <= n; i++) {
        scanf("%I64d", &tck[i]);
        pq.push( node(i, tck[i]) );
    }

    while(!pq.empty()) {
        node u = pq.top();
        //cout << endl << u.p << "  " << u.cost << endl;;
        pq.pop();

        if(u.cost > tck[u.p])
            continue;

        for(ll k = 0; k < graph[u.p].size(); k++) {
            if(tck[u.p] + cost[u.p][k] < tck[ graph[u.p][k] ]) {

                //cout << endl << u.cost << "  " << cost[u.p][k] << " uugujg " << graph[u.p][k] << endl;
                tck[ graph[u.p][k] ] = tck[u.p] + cost[u.p][k];
                pq.push( node(graph[u.p][k], tck[ graph[u.p][k] ]) );
            }

        }
    }

    for(ll i = 1; i <= n; i++) {
        printf("%I64d", tck[i]);
        if(i != n)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}