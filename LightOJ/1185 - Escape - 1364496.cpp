#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> g[110];
bitset <2> v[110];
ll cnt = 0;
void dfs(ll u, bool state, ll p)
{
    if(v[u][state])
        return;
    if(state && p != -1) cnt++;
    if(p != -1)
        v[u][state] = 1;
      for(ll i = 0; i < g[u].size(); i++)
        dfs(g[u][i], state ^ 1, u);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 105; i++) {
            g[i].clear();
            v[i].reset();
        }
          ll n, e;
        scanf("%lld %lld", &n, &e);
          for(ll i = 1; i <= e; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
          cnt = 0;
        dfs(1, 1, -1);
          printf("Case %lld: %lld\n", ++caseno, cnt);
      }
      return 0;
}
 
