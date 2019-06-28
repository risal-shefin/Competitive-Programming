#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> tree[200009], ans;
ll sz[200009];
void dfs(ll u, ll p)
{
    for(ll i = 0; i < tree[u].size(); i++) {
        ll nd = tree[u][i];
        if(nd == p)
            continue;
        dfs(nd, u);
    }
    if(sz[u] % 2 != 0 || sz[u] == 0)
        return;
    ans.push_back(u);
    sz[u] = 0;
    for(ll i = 0; i < tree[u].size(); i++) {
        ll nd = tree[u][i];
        sz[nd]--;
        if(sz[nd] == 0)
            ans.push_back(nd);
    }
}
void dfs2(ll u, ll p)
{
    if(sz[u] % 2 == 0 && sz[u] != 0) {
        ans.push_back(u);
        sz[u] = 0;
        for(ll i = 0; i < tree[u].size(); i++) {
            ll nd = tree[u][i];
            sz[nd]--;
            if(sz[nd] == 0)
                ans.push_back(nd);
        }
    }
    for(ll i = 0; i < tree[u].size(); i++) {
        ll nd = tree[u][i];
        if(nd == p)
            continue;
        dfs2(nd, u);
    }
}
int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll u;
        scanf("%lld", &u);
        if(u == 0) continue;
        tree[u].push_back(i);
        tree[i].push_back(u);
    }
    if(n == 1) {
        cout << "YES" << endl << 1 << endl;
        return 0;
    }
    for(ll i = 1; i <= n; i++)
        sz[i] = tree[i].size();
    dfs(1, 0);
    dfs2(1, 0);
    if(ans.size() != n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(ll i = 0; i < ans.size(); i++)
        printf("%lld\n", ans[i]);
    return 0;
}
