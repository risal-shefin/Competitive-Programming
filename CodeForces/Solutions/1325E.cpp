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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MAX = 1e6 + 10;
vector <ll> prime;
bitset <MAX> check;
vector <pll> g[MAX];
ll vis[MAX], visEdge[MAX], lev[MAX];

ll bfs(ll src)
{
    queue <ll> q;
    q.push(src);
    vis[src] = src, lev[src] = 0;

    ll ret = inf;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(pll &v : g[u]) {
            if(visEdge[v.second] == src)
                continue;

            if(vis[v.first] == src)
                ret = min(ret, lev[u] + lev[v.first] + 1);
            else {
                lev[v.first] = lev[u] + 1;
                vis[v.first] = visEdge[v.second] = src;
                q.push(v.first);
            }
        }
    }

    return ret;
}

int main()
{
    for(ll i = 2; i < MAX; i++) {
        if(!check[i]) {
            prime.pb(i);

            for(ll j = i * i; j < MAX; j += i)
                check[j] = 1;
        }
    }

    ll n, chk = 0, edgeno = 0;
    cin >> n;
    for1(i, n) {
        ll inp, p1 = -1, p2 = -1;
        sl(inp);

        for(ll j = 0; j < prime.size() && prime[j] * prime[j] <= inp; j++) {
            if(inp % prime[j] == 0) {
                ll cnt = 0;
                while(inp % prime[j] == 0) {
                    inp /= prime[j];
                    cnt++;
                }
                if(cnt & 1) {
                    if(p1 == -1)    p1 = prime[j];
                    else p2 = prime[j];
                }
            }
        }
        if(inp > 1) {
            if(p1 == -1) p1 = inp;
            else p2 = inp;
        }

        if(p1 == -1)
            chk = 1;
        else {
            ll u = p1, v;
            if(p2 == -1) v = 1;
            else v = p2;

            g[u].pb(mp(v, edgeno));
            g[v].pb(mp(u, edgeno));
            edgeno++;
        }

    }
    if(chk) {
        pf("1\n");
        return 0;
    }

    ll ans = bfs(1);
    for(ll i = 0; i < prime.size() && prime[i]*prime[i] < MAX; i++) {
        ll src = prime[i];
        ans = min(ans, bfs(src));
    }

    if(ans == inf)
        cout << -1 << endl;
    else
        pf("%lld\n", ans);

    return 0;
}