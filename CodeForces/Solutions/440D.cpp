#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define inf 10000000000000

vector <ll> g[409], indx[409], lst[409][409], tlst[409];
ll dp[409][409], temp[409];
pll connect[409];

void dfs(ll u, ll p)

{
    dp[u][1] = g[u].size();
    for(ll id: indx[u]) lst[u][1].push_back(id);

    for(ll nd: g[u]) {
        if(nd == p) continue;

        dfs(nd, u);

        for(ll i = 1; i <= 400; i++) {
            temp[i] = dp[u][i];
            tlst[i].clear();
            tlst[i].insert(tlst[i].begin(), lst[u][i].begin(), lst[u][i].end());
        }
        for(ll i = 1; i <= 400; i++) {
            for(ll j = 1; i + j <= 400; j++) {
                if(dp[nd][j] == inf || dp[u][i] == inf)
                    continue;

                if(dp[u][i] - 1 + dp[nd][j] - 1 < temp[i + j]) {
                    temp[i + j] = dp[u][i] - 1 + dp[nd][j] - 1;

                    tlst[i + j].clear();
                    for(ll id: lst[u][i]) {
                        if(connect[id].first == nd || connect[id].second == nd)
                            continue;
                        tlst[i + j].push_back(id);
                    }
                    for(ll id: lst[nd][j]) {
                        if(connect[id].first == u || connect[id].second == u)
                            continue;
                        tlst[i + j].push_back(id);
                    }
                }
            }
        }
        for(ll i = 1; i <= 400; i++) {
            if(temp[i] < dp[u][i]) {
                dp[u][i] = temp[i];
                lst[u][i].clear();
                lst[u][i].insert(lst[u][i].begin(), tlst[i].begin(), tlst[i].end());
            }
        }
    }
}

int main()

{
    for(ll i = 0; i <= 402; i++)
        for(ll j = 0; j <= 402; j++)
            dp[i][j] = inf;

    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);

        indx[u].push_back(i);
        indx[v].push_back(i);

        connect[i] = pll(u, v);
    }

    dfs(1, -1);

    ll city, ans = inf;
    for(ll i = 1; i <= n; i++) {
        if(dp[i][k] < ans) {
            ans = dp[i][k];
            city = i;
        }
    }

    cout << ans << endl;
    for(ll id: lst[city][k]) printf("%lld ", id);
    if(lst[city][k].size() != 0) printf("\n");

    return 0;
}