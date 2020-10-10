#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector <ll> g[300009];
bool vis[300009];

void dfs(ll u)

{
    vis[u] = 1;
    for(ll v: g[u]) {
        if(vis[v])
            continue;

        dfs(v);
    }
}

ll col[300009], sz[10];


int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i =1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);
    for(ll i = 1; i <= n; i++) {

        if(!vis[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(ll j = 1; j <= 3; j++) {
        memset(vis, 0, sizeof(vis));

        for(ll i = 1; i <= n; i++) {
            if(col[i] != 0)
                continue;

            for(ll v: g[i])
                vis[v] = 1;

            for(ll k = 1; k <= n; k++) {
                if(vis[k] == 0 && col[k] != 0) {
                    cout << -1 << endl;
                    return 0;
                }

                if(col[k] == 0 && vis[k] == 0) {
                    col[k] = j;
                    sz[j]++;
                }
            }
            break;
        }
    }

    if(sz[1] + sz[2] + sz[3] != n || sz[1] == 0 || sz[2] == 0 || sz[3] == 0) {
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 1; i <= n; i++) {
        ll rest = n - sz[col[i]];
        if(rest != g[i].size()) {
            cout << -1 << endl;
            return 0;
        }

        for(ll v : g[i]) {
            if(col[i] == col[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", col[i]);
    }


    cout << endl;

    return 0;
}