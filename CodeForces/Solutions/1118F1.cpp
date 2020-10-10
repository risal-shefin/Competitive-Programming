#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll col[300009], subr[300009], subb[300009], ans = 0;
ll totr = 0, totb = 0;

vector <ll> g[300009];

void dfs(ll u, ll p)

{
    if(col[u] == 1) {
        subr[u]++;
        totr++;
    }
    if(col[u] == 2) {
        subb[u]++;
        totb++;
    }

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        dfs(nd, u);

        subr[u] += subr[nd];
        subb[u] += subb[nd];
    }
}

void dfs2(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        ll remr = totr - subr[nd], remb = totb - subb[nd];
        if( !(subb[nd] > 0 && subr[nd] > 0) && !(remr > 0 && remb > 0)) {
            ans++;
            //cout << u << "  " << nd << endl;
        }

        dfs2(nd, u);;
    }

//    for(ll i = 0; i < g[u].size(); i++) {
//        ll nd = g[u][i];
//        if(nd == p)
//            continue;
//        dfs2(nd, u);
//    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &col[i]);
    }

    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    dfs2(1, 0);

    cout << ans << endl;

    return 0;
}