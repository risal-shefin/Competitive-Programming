#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
vector <ll> graph[100009], path;
bool chk = 1;
ll nd;
void dfs(ll u, ll p)
{
    if(graph[u].size() == 1 && u != nd) {
        path.push_back(u);
        return;
    }
    for(ll i = 0; i < graph[u].size(); i++) {
        if( graph[u][i] == p)
            continue;
        dfs(graph[u][i], u);
    }
}
int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    /*dfs(1, -1, 1);
    for(ll i = 1; i <= n; i++) {
        if(path[i].size() < 1)
            continue;
        for(ll j = 0; j < path[i].size(); j++) {
            printf("%lld %lld\n", i, path[i][j]);
        }
    }*/
    ll cnt = 0;
    ll mx = 0;
    for(ll i = 1; i <= n; i++) {
        if(graph[i].size() > mx) {
            mx = graph[i].size();
            nd = i;
        }
    }
    for(ll i = 1; i <= n; i++) {
        if(nd == i)
            continue;
        if(graph[i].size() > 2) {
            printf("No\n");
            return 0;
        }
    }
    dfs(nd, -1);
    cnt = path.size();
    printf("Yes\n");
    printf("%lld\n", cnt);
    for(ll j = 0; j < path.size(); j++) {
        printf("%lld %lld\n", nd, path[j]);
    }
    return 0;
}
