#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector <ll> graph[200009];
ll cst[200009], par[200009], sub[200009], pani[200009], tme[200009], TM = 1;
bool is[200009];

struct node {
    ll u;
    ll v;
} edge[200009];

ll findpar(ll u)

{
    if(par[u] == u) return u;
    return par[u] = findpar( par[u] );
}

ll dfs(ll u, ll p)

{
    tme[u] = TM++;
    ll ret = 0;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        ret += dfs(nd, u);
    }

    return pani[u] = ret + cst[u];
}

int main()

{
    ll n;
    cin >> n;

    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &cst[i]);
        par[i] = i;
        sub[i] = 1;
        sum += cst[i];
    }

    ll m;
    cin >> m;
    for(ll i = 1; i <= m; i++) {
        is[i] = 0;
        ll u, v;
        scanf("%lld %lld", &u, &v);

        edge[i].u = u;
        edge[i].v = v;

        ll pu = findpar(u);
        ll pv = findpar(v);

        if(pu == pv)
            continue;

        if(sub[pu] < sub[pv])
            swap(pu, pv);

        sub[pu] += sub[pv];
        par[ pv ] = pu;
        is[i] = 1;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    if(sum != 0) {
        printf("Impossible\n");
        return 0;
    }
    printf("Possible\n");

    dfs(1, -1);

    for(ll i = 1; i <= m; i++) {
        if(!is[i]) {
            printf("0\n");
            continue;
        }

        ll u = edge[i].u;
        ll v= edge[i].v;

        if(tme[u] < tme[v])
            printf("%lld\n", pani[v]);
        else
            printf("%lld\n", -pani[u]);
    }

    return 0;
}