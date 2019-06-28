#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cst[105][105], cost = 0;
vector <ll> graph[105];
bool chk = 0;
void dfs(ll u, ll p)
{
    if(u == 1 && p != -1)
        return;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(u == 1 && chk == 0 && i == 1)
            continue;
        if(u == 1 && chk == 1 && i == 0)
            continue;
          if(nd != p) {
            dfs(nd, u);
            cost += cst[u][nd];
        }
    }
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i < 103; i++) {
            graph[i].clear();
            for(ll j = 0; j < 103; j++)
                cst[i][j] = 0;
        }
        chk = 0;
        cost = 0;
          ll n;
        scanf("%lld", &n);
        for(ll i = 0; i < n; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            graph[u].push_back(v);
            graph[v].push_back(u);
              cst[v][u] = c;
        }
          dfs(1, -1);
        ll ans = cost;
        chk ^= 1;
        cost = 0;
        dfs(1, -1);
        ans = min(ans, cost);
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
