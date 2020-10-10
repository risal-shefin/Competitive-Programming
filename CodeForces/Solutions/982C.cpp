#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sl(val) scanf("%lld", &val)
#define inf 2e18
#define pb push_back

vector <ll> graph[100009];
ll n, cnt = 0;

ll dfs(ll u, ll p)

{
    ll ret = 1;

    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;
        ll num = dfs(nd, u);
        if(num % 2 == 0 && (n - num) % 2 == 0)
            cnt++;
        ret += num;
    }

    return ret;
}

int main()

{
    ll u ,v;
    cin >> n;

    for(ll i = 1; i < n; i++) {
        sl(u), sl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1);

    if(n % 2 != 0 && cnt == 0) {
        printf("-1\n");
    }
    else {
        printf("%lld\n", cnt);
    }

    return 0;
}