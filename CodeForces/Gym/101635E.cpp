#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll d, c, p;
};

vector <node> g[10009];
map <string, ll> numOf;
ll mark[10009], c[10009], p[10009];
ll dp[2][10005];

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll b, n;
    cin >> b >> n;
    if(n == 0) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }

    ll indx = 0;
    for(ll i = 1; i <= n; i++) {
        string u, v, ing;
        ll p, c;
        cin >> u >> v >> ing >> c >> p;

        if(numOf.find(u) == numOf.end())
            numOf[u] = ++indx;
        if(numOf.find(v) == numOf.end())
            numOf[v] = ++indx;

        g[ numOf[v] ].push_back({numOf[u], c, p});

        mark[ numOf[u] ]++;
    }

    queue <ll> q;
    for(ll i = 1; i <= indx; i++) {
        c[i] = 1e18;
        p[i] = -1;
        if(mark[i] == 0) {
            q.push(i);
            c[i] = 0;
            p[i] = 0;
        }
    }

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(node nd : g[u]) {
            ll co = c[u] + nd.c;
            ll pres = p[u] + nd.p;

            if(co < c[nd.d]) {
                c[nd.d] = co;
                p[nd.d] = pres;

            }
            else if(co == c[nd.d] && pres > p[nd.d])
                p[nd.d] = pres;

            mark[nd.d]--;
            if(mark[nd.d] == 0)
                q.push(nd.d);
        }
    }

    ll prv = 0, now = 1;
    for(ll i = 0; i <= b; i++)
        dp[0][i] = 0;

    for(ll i = 1; i <= indx; i++) {
        ll cst = c[i], pres = p[i];
        //cout << lst[i] << "  " << cst << "  " << pres << endl;

        for(ll j = 0; j <= b; j++) {
            if(cst > j)
                dp[now][j] = dp[prv][j];
            else
                dp[now][j] = max(dp[prv][j], pres + dp[prv][j - cst]);
        }

        now ^= 1;
        prv ^= 1;
    }

    now = prv;
    ll ansc = 1e18, ansp = dp[now][b];
    for(ll i = b; i >= 0; i--) {
        if(dp[now][i] == ansp)
            ansc = i;
    }

    cout << ansp << endl << ansc << endl;

    return 0;
}