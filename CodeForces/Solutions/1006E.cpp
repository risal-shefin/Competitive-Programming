#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll TM = 0, start[200009], ft[200009], nodeOf[1000009];
vector <ll> graph[200009];

void dfs(ll u, ll p)

{
    start[u] = ++TM;
    nodeOf[TM] = u;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        dfs(nd, u);
    }

    ft[u] = TM;
}

int main()

{
    ll n, q;
    cin >> n >> q;
    for(ll i = 2; i <= n; i++) {
        ll v;
        scanf("%lld", &v);
        graph[i].pb(v);
        graph[v].pb(i);
    }

    for(ll i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(1, -1);

    for(ll i = 1; i <= q; i++) {
        ll u, num;
        scanf("%lld %lld", &u, &num);
        ll tme = start[u] + num - 1;

        if(tme > ft[u]) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", nodeOf[tme]);

    }

    return 0;
}