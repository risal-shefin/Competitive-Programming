#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair <ll, ll>
vector <pll> g[20009];
ll ans = 0, num[20009];
void dfs(ll u, ll p)
{
    for(pll v: g[u]) {
        if(v.first == p)
            continue;
          dfs(v.first, u);
          if(v.second == 1) {
            if(num[v.first] < 0)
                num[u] += num[v.first];
            else {
                ans += num[v.first] + 1;
                num[u]--;
            }
        }
        else {
            if(v.second == -1) {
                if(num[v.first] > 0)
                    num[u] += num[v.first];
                else
                    num[u]++;
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
        for(ll i = 1; i < n; i++) {
            ll u, v;
            scanf("%lld %lld", &u, &v);
              g[u].push_back(pll(v, 1));
            g[v].push_back(pll(u, -1));
        }
          ans = 0;
        dfs(0, -1);
          if(num[0] > 0)
            ans += num[0];
          printf("Case %lld: %lld\n", ++cs, ans);
          for(ll i = 0; i <= 20002; i++) {
            num[i] = 0;
            g[i].clear();
        }
    }
      return 0;
}
 
