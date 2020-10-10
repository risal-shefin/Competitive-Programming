#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll state[100009], col[100009];
vector <ll> room[100009];
vector <pair<ll,ll>> g[100009];

ll bfs(ll node)

{
    col[node] = 0;
    queue <ll> q;
    q.push(node);
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(pair <ll, ll> v: g[u]) {
            if(v.second == 0) {
                if(col[v.first] == -1) {
                    col[v.first] = col[u] ^ 1;
                    q.push(v.first);
                }
                else if(col[v.first] != col[u] ^ 1)
                    return -1;
            }
            else {
                if(col[v.first] == -1) {
                    col[v.first] = col[u];
                    q.push(v.first);
                }
                else if(col[v.first] != col[u])
                    return -1;
            }
        }
    }
    return 1;
}

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &state[i]);

    for(ll i = 1; i <= m; i++) {
        ll tot;
        scanf("%lld", &tot);
        for(ll j = 1; j <= tot; j++) {
            ll inp;
            scanf("%lld", &inp);
            room[inp].push_back(i);
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(state[i] == 0) {
            g[room[i][0]].push_back(make_pair(room[i][1], 0));
            g[room[i][1]].push_back(make_pair(room[i][0], 0));
        }
        else {
            g[room[i][0]].push_back(make_pair(room[i][1], 1));
            g[room[i][1]].push_back(make_pair(room[i][0], 1));
        }
    }

    memset(col, -1, sizeof(col));
    ll ret;
    for(ll i = 0; i < m; i++) {
        if(col[i] == -1)
            ret = bfs(i);
        if(ret == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}