#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> graph[10009];
ll par[10009], maf[10009], ans = 0;
ll dfs(ll u, ll p)
{
    ll ret = maf[u] - 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
           continue;
                   ll tmp = dfs(nd, u);
         ans += abs(tmp);
         ret += tmp;
    }
        return ret;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i <= 10000; i++)
             graph[i].clear();
        ll n;
        scanf("%lld", &n);
                for(ll i = 1; i <= n; i++) {
            ll u, m, num;
            scanf("%lld %lld %lld", &u, &m, &num);
                        maf[u] = m;
                        for(ll j = 1; j <= num; j++) {
                ll v;
                scanf("%lld", &v);
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
                ans = 0;
        dfs(1, -1);
        printf("Case %lld: %lld\n", ++caseno, ans);
    }
    return 0;
}
