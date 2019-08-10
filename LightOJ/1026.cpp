#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define pb push_back

vector <ll> g[10009];
vector <pll> ans;
bool vis[10009];
ll low[10009], start[10009], TM = 1;

void clr() {
    for(ll i = 0; i <= 10000; i++) g[i].clear();
    memset(vis, 0, sizeof(vis));
    TM = 1;
    ans.clear();
}

void dfs(ll u, ll p) {
    low[u] = start[u] = TM++;
    vis[u] = 1;

    for(ll v: g[u]) {
        if(v == p)
            continue;

        if(vis[v])
            low[u] = min(low[u], start[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(start[u] < low[v]) {
                ll p1 = u, p2 = v;
                if(p1 > p2) swap(p1, p2);
                ans.push_back( pll(p1, p2) );
            }
        }
    }
}

int main()

{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            ll u, tot;
            scanf("%lld (%lld)", &u, &tot);

            for(ll j = 1; j <= tot; j++) {
                ll inp;
                scanf("%lld", &inp);
                g[u].push_back(inp);
            }
        }

        for(ll i = 0; i <= 10000; i++) {
            if(!vis[i])
                dfs(i, -1);
        }

        printf("Case %lld:\n%lld critical links\n", ++cs, (ll)ans.size());
        sort(ans.begin(), ans.end());
        for(pll p: ans) {
            printf("%lld - %lld\n", p.first, p.second);
        }

        clr();
    }

    return 0;
}
