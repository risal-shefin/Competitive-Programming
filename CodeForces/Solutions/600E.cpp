#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <ll, ll>

vector <ll> graph[100009];
ll col[100009], sz[100009], TM = 1, st[100009], en[100009], nodeOf[400009], cnt[100009];
ll ans[100009];

void szdfs(ll u, ll p)

{
    st[u] = TM;
    nodeOf[TM] = u;
    TM++;
    sz[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        szdfs(nd, u);
        sz[u] += sz[nd];
    }
    en[u] = TM++;
}

pii dfs(ll u, ll p, bool keep)

{
    ll bigchild = -1, mx = -1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];

        if(nd != p && sz[nd] > mx) {
            mx = sz[nd];
            bigchild = nd;
        }
    }

    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];

        if(nd != p && nd != bigchild)
            dfs(nd, u, 0);
    }

    pii tmp = make_pair(0, 0);
    if(bigchild != -1)
        tmp = dfs(bigchild, u, 1);

    ll sum = 0, curmx = 0;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];

        if(nd != p && nd != bigchild) {
            for(ll t = st[nd]; t < en[nd]; t++) {

                if(nodeOf[t] == 0)
                    continue;
                cnt[ col[ nodeOf[t] ] ]++;

                if(cnt[ col[ nodeOf[t] ] ] > curmx) {
                    curmx = cnt[ col[ nodeOf[t] ] ];
                    sum = col[ nodeOf[t] ];
                }
                else if(cnt[ col[ nodeOf[t] ] ] == curmx)
                    sum += col[ nodeOf[t] ];
            }
        }
    }

    cnt[ col[u] ]++;
    if(cnt[ col[u] ] > curmx) {
        curmx = cnt[ col[u] ];
        sum = col[u];
    }
    else if(cnt[ col[u] ] == curmx)
        sum += col[u];
        
    if(tmp.first > curmx) {
        sum = tmp.second;
        curmx = tmp.first;
    }
    else if(tmp.first == curmx)
        sum += tmp.second;

    ans[u] = sum;
    if(keep == 0) {
        for(ll t = st[u]; t < en[u]; t++)
            cnt[ col[ nodeOf[t] ] ]--;
    }

    return make_pair(curmx, sum);
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll c;
        scanf("%lld", &c);
        col[i] = c;
    }

    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    szdfs(1, -1);
    dfs(1, -1, 0);

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;

    return 0;
}