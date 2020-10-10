#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define siz 100009
#define pb push_back
vector <ll> graph[siz];
vector <ll> result;
ll s, dp[100009][2], m, visit[100009][2];

ll solve(ll u, ll id, ll counter)

{
    if(visit[u][id] && counter > m) {
        return 2;
    }
    if(counter >= 1000000) {
        return 2;
    }

    visit[u][id] = 1;
    if(dp[u][id] != -1)
        return dp[u][id];
    if(graph[u].size() == 0) {
        if(id == 0)
            return dp[u][id] = 1;
        else {
            result.pb(u);
            return dp[u][id] = 0;
        }
    }

    ll tmp = 0;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll state = solve(graph[u][i], id ^ 1, counter + 1);
        if(state == 0) {
            result.pb(u);
            return dp[u][id] = 0;
        }
        if(state == 2)
            tmp = 1;
    }

    if(tmp == 1) {
        return dp[u][id] = 2;
    }
    else
        return dp[u][id] = 1;

}

int main()

{
    ll n;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    for(ll i = 1; i <= n; i++) {
        ll cnt;
        scanf("%lld", &cnt);
        for(ll j = 1; j <= cnt; j++) {
            ll v;
            scanf("%lld", &v);
            graph[i].pb(v);
        }
    }

    scanf("%lld", &s);
    ll state = solve(s, 0, 0);

    if(state == 0) {
        cout << "Win" << endl;
        for(ll i = result.size() - 1; i >= 0; i--) {
            printf("%lld", result[i]);
            if(i != 0)
                printf(" ");
            else
                printf("\n");
        }
    }
    else if(state == 1)
        cout << "Lose" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}