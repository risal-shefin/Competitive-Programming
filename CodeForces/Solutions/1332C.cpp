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

const ll sz = 2e5 + 10;
char s[sz];
ll n, k, comp, cnt[30];
bool vis[sz];
vector <ll> lst[sz];

void dfs(ll u)
{
    vis[u] = 1;
    lst[comp].pb(u);

    ll rv = n - u + 1;
    if(!vis[rv]) dfs(rv);

    ll nxt = u + k;
    if( nxt <= n && !vis[nxt]) dfs(nxt);

    ll prv = u-k;
    if(prv >= 1 && !vis[prv]) dfs(prv);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(k);
        scanf("%s", s+1);

        comp = 0;
        for1(i, n) {
            if(vis[i])
                continue;

            comp++;
            dfs(i);
        }

        ll ans = 0;
        for(ll i = 1; i <= comp; i++) {
            ms(cnt, 0);

            ll mx = 0;
            for(ll id : lst[i]) {
                ll now = s[id] - 'a';
                cnt[now]++;

                mx = max(mx, cnt[now]);
            }

            ans += ( (ll)lst[i].size() - mx);
        }

        pf("%lld\n", ans);


        for(ll i = 1; i <= n; i++) {
            vis[i] = 0;
            lst[i].clear();
        }
    }

    return 0;
}