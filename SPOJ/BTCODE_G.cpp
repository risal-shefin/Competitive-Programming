#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> graph[100009];
ll col[100009], par[100009];

ll findr(ll u)

{
    if(par[u] == u)
        return u;
    return par[u] = findr(par[u]);
}

void merg(ll u)

{
    ll pu = findr(u);
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(col[nd] != col[u])
            continue;

        ll pv = findr(nd);
        if(pu == pv)
            continue;

        par[pv] = pu;
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
        par[i] = i;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll q;
    cin >> q;
    while(q--) {
        ll state, u, v;
        scanf("%lld %lld %lld", &state, &u, &v);
        if(state == 1) {
            col[u] = v;
            merg(u);
        }
        else {
            if(col[u] == 0 || col[v] == 0) {
                printf("NO\n");
                continue;
            }
            ll pu = findr(u);
            ll pv = findr(v);
            if(pu == pv)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
