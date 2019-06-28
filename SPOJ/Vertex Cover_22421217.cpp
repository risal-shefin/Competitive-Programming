#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector <ll> graph[100009];
ll dp[100009][2];
ll dfs(ll u, ll p, bool state)
 {
    ll &ret = dp[u][state];
    if(ret != -1)
        return ret;
    ll rt = 0;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        rt += min( (ll)(state ^ 1) + dfs(nd, u, state ^ 1), 1 + dfs(nd, u, state | 1) );
    }
     return ret = rt;
}
int main()
 {
    memset(dp, -1, sizeof(dp) );
     ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
     ll ans1 = dfs(1, -1, 0);
    ll ans2 = 1 + dfs(1, -1, 1);
     //cout << ans1 << "  " << ans2 << endl;
    cout << min(ans1, ans2) << endl;
     return 0;
