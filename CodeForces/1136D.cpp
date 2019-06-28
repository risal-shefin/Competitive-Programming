#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> g[300009];
ll ara[300009];
set <ll> st[300009];
int main()
{
    ll n, e, lst;
    cin >> n >> e;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }
    for(ll i = 1; i <= e; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[v].push_back(u);
    }
    ll p = 0, ans = 0;
    for(ll i = n; i >= 1; i--) {
        ll now = ara[i];
        if(st[now].size() == p && i != n)
            ans++;
        else {
            for(ll j = 0; j < g[now].size(); j++)
                st[g[now][j]].insert(now);
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}
