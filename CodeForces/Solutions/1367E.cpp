// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e3 + 10;

ll cnt[30];
vector <ll> g[sz], comp;
bool vis[sz];
char s[sz];
multiset <int> val;

ll dfs(ll u)
{
    vis[u] = 1;
    ll ret = 1;
    for(ll &v : g[u]) if(!vis[v]) ret += dfs(v);

    return ret;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        sl(n), sl(k);
        scanf("%s", s);

        for0(i, n) cnt[s[i] - 'a']++;
        sort(cnt, cnt+26, greater<ll>());

        ll ans = 0;
        rep1(len, n) {
            ll turn = k % n;

            for0(i, len) g[i].clear();
            for0(i, len) {
                ll nxt = (i + k) % len;
                g[i].pb(nxt);
            }

            ms(vis, 0); comp.clear();
            for0(i, len) if(!vis[i]) comp.pb(dfs(i));
            sort(all(comp));

            val.clear();
            for0(i, 26) val.insert(cnt[i]);

            bool ok = 1;
            for(ll &same: comp) {
                ll mx = *val.rbegin();
                if(mx < same) {
                    ok = 0;
                    break;
                }

                val.erase(val.find(mx));
                val.insert(mx - same);
            }

            if(ok) {
                ans = len;
                break;
            }
        }

        pf("%lld\n", ans);
        ms(cnt, 0);
    }

    return 0;
}