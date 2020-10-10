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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 5e5 + 10;
vector <ll> g[sz], ans, lst[sz], tmp;
ll cnt[sz], lv[sz];
bool vis[sz];

int main()
{
    ll n, m;
    sl(n), sl(m);

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) {
        sl(cnt[i]);
        lst[ cnt[i] ].pb(i);
    }

    bool ok = 1;
    for1(i, n) {
        for(ll &v : g[i]) {
            if(cnt[i] == cnt[v]) {
                ok = 0;
                break;
            }
        }
    }
    if(!ok) {
        cout << -1 << endl;
        return 0;
    }

    for(ll &v : lst[1]) {
        ans.pb(v);
        lv[v] = 1;
    }

    for(ll i = 2; i <= n && ok; i++) {
        for(ll &now : lst[i]) {
            for(ll &v : g[now]) {
                if(lv[v] == 0)
                    continue;

                tmp.pb(lv[v]);
            }

            sort(all(tmp));
            tmp.erase(unique(all(tmp)), tmp.end());

            if(tmp.size() != i-1) {
                ok = 0;
                break;
            }

            lv[now] = i;
            ans.pb(now);
            tmp.clear();
        }
    }

    if(ans.size() != n || !ok) {
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 0; i < ans.size(); i++) {
        if(i != 0) pf(" ");
        pf("%lld", ans[i]);
    }
    pn;

    return 0;
}