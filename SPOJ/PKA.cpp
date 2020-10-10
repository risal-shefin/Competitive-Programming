#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct node {
    ll b, e;
    bool operator <(const node &a) const {
        if(b == a.b)
            return e > a.e;
        return b < a.b;
    }

} ara[305];

ll child[305];
bool vis[305];
ll n;

ll dfs(ll u) {

    if(vis[u])
        return child[u];

    vis[u] = 1;
    child[u] = 0;
    ll valEnd[305];

    for(ll i = u+1; i <= n; i++) {
        if(ara[i].e > ara[u].e)
            continue;

        ll val = dfs(i);
        ll now = val;

        for(ll j = u+1; j < i; j++) {
            if(ara[i].b >= ara[j].e)
                val = max(val, valEnd[j] + now);
        }

        valEnd[i] = val;
        child[u] = max(child[u], val);
    }

    return ++child[u];
}

int main()

{
//    freopen("in.txt", "r", stdin);
//    freopen("out1.txt", "w", stdout);
    ll t;
    sl(t);
    while(t--) {
        ll idx = 0;
        sl(n);
        forn(i, n)
            sl(ara[i].b), sl(ara[i].e);

        sort(ara + 1, ara + n + 1);

        ms(vis, 0);
        ara[0] = {-1, inf};
        ll ans = dfs(0) - 1;
//        forn(i, n) {
//            if(!vis[i])
//                ans = max(ans, dfs(0));
//        }

        pf("%lld\n", ans);
    }

    return 0;
}

