#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector < pair<ll,ll> > graph[1009];
ll dfs(ll u, ll p)
{
    ll ret = 0;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i].first;
        ll cst = graph[u][i].second;
        if(nd != p) {
            ll tmp = dfs(nd, u);
            if(cst == 1)
                ret ^= (tmp + 1);
            else
                ret ^= tmp ^ (cst & 1);
        }
      }
      return ret;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i < n; i++) {
            ll u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            graph[u].push_back( make_pair(v, w) );
            graph[v].push_back( make_pair(u, w) );
        }
          if(dfs(0, -1))
            printf("Case %lld: Emily\n", ++caseno);
        else
            printf("Case %lld: Jolly\n", ++caseno);
          for(ll i = 0; i <= 1000; i++)
            graph[i].clear();
    }
      return 0;
}
 
