#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector <ll> g[200009];
ll col[200009];
set <ll> st;

void dfs(ll u, ll p)

{
    ll cl = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        if(p != -1) {
            while(cl == col[p] || cl == col[u])
                cl++;
            col[nd] = cl;
            st.insert(cl);
            cl++;
        }
        else {
            while(cl == col[u])
                cl++;
            col[nd] = cl;
            st.insert(cl);
            cl++;
        }
    }

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p)
            continue;

        dfs(nd, u);
    }
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    col[1] = 1;
    st.insert(1);
    dfs(1, -1);

    cout << st.size() << endl;
    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", col[i]);
    }

    printf("\n");

    return 0;
}