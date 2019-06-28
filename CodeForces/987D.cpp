#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
bool check[109];
vector <ll> graph[100009];
ll ara[100009], ans[100009];
bitset <100009> vis;
struct node {
    ll u;
    ll level;
    node(ll _u, ll _lev) {
        u = _u;
        level = _lev;
    }
};
int main()
{
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }
    for(ll i = 1; i <= m; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(ll j = 1; j <= n; j++) {
        if(s == 1) {
            ans[j] = 0;
            continue;
        }
        vis.reset();
        memset(check, 0, sizeof(check));
        ll cnt = 1, res = 0;
        bool state = 0;
        queue <node> q;
        q.push( node(j, 0) );
        vis[j] = 1;
        check[ ara[j] ] = 1;
        while(!q.empty()) {
            node tmp = q.front();
            q.pop();
            ll u = tmp.u;
            ll lev = tmp.level;
            for(ll i = 0; i < graph[u].size(); i++) {
                ll nd = graph[u][i];
                if(!check[ ara[nd] ]) {
                    check[ ara[nd] ] = 1;
                    cnt++;
                    res += lev + 1;
                    if(cnt == s) {
                        state = 1;
                        ans[j] = res;
                        break;
                    }
                }
                if(!vis[nd]) {
                    q.push( node(nd, lev + 1));
                    vis[nd] = 1;
                }
            }
            if(state)
                break;
        }
    }
    for(ll i = 1; i <= n; i++) {
        if(i > 1)
            printf(" ");
        printf("%lld", ans[i]);
    }
    cout << endl;
    return 0;
}
