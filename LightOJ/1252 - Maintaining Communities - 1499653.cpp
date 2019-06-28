#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair <ll, ll>
vector <pll> g[101];
ll k, ans;
ll dfs(ll u, ll p)
{
    ll sum = 0;
    vector <ll> v;
      for(ll i = 0; i < g[u].size(); i++) {
        pll nd = g[u][i];
        if(nd.first == p)
            continue;
          v.push_back(dfs(nd.first, u) + nd.second);
    }
    sort(v.begin(), v.end());
      for(ll i = 0; i < v.size(); i++) {
        if(v[i] + sum > k)
            ans++;
        else
            sum += v[i];
    }
      return sum;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n, u, v, w;
        scanf("%d %d", &n, &k);
          for(ll i = 1; i < n; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(pll(v, w));
            g[v].push_back(pll(u, w));
        }
          ans = 0;
        dfs(1, -1);
          printf("Case %d: %d\n", ++cs, ans + 1);
          for(ll i = 1; i <= n; i++)
            g[i].clear();
    }
      return 0;
}
 
