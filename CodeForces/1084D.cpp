#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll oil[300009];
vector <ll> tree[300009], cst[300009];
ll ans = 0;
ll dfs(ll u, ll p)
{
    ll mx1 = 0, mx2 = 0;
    for(ll i = 0; i < tree[u].size(); i++) {
        ll nd = tree[u][i];
        if(nd == p)
            continue;
        ll ret = dfs(nd, u);
        ret = max(0LL, ret - cst[u][i]);
        if(ret >= mx1) {
            mx2 = mx1;
            mx1 = ret;
        }
        else if(ret > mx2) mx2 = ret;
    }
    ans = max(ans, oil[u] + mx1 + mx2);
    //cout << oil[u] + mx1 + mx2 << "  " << u << "  " << mx1 << "  " << mx2 <<  endl;
    return oil[u] + mx1;
}
int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &oil[i]);
        ans = max(ans, oil[i]);
    }
    for(ll i = 1; i < n; i++) {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        tree[u].pb(v);
        tree[v].pb(u);
        cst[u].pb(w);
        cst[v].pb(w);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
