#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define inf 1e18
#define sl(val) scanf("%lld", &val)
vector <ll> graph[300009];
ll n, x, y, tot, mn = 0, state = 0, dist = 0, prv = 0, cnt2 = 0;
ll dfs(ll u, ll p, ll cnt)
{
    ll ret = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        if(graph[u][i] == p)
            continue;
        ll tmp = dfs( graph[u][i], u, cnt + 1);
        if(graph[u][i] == y) {
            state = 1;
            //cout << tmp << "  " << ret << endl;
            dist = tmp;
        }
        if(!state && u == x) {
            //cout << tmp << endl;
            cnt2 += tmp;
        }
        if(state && u == x)
            state = 0;
        ret += tmp;
    }
    //cout << u << "  " << ret << endl;
    return ret;
}
int main()
{
    cin >> n >> x >> y;
    tot = (n * (n - 1));
    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(x, -1, 0);
    //cout << dist << endl;
    ll bad = dist * cnt2;
    tot -= (dist + bad);
    cout << tot << endl;
    return 0;
}
