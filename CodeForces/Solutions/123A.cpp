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

const ll sz = 1e3 + 10;
char s[sz];

vector <ll> g[sz], comp[sz];
bool vis[sz];

ll cnt[26], idc;
set <pll> lst;

void dfs(ll u)
{
    vis[u] = 1, comp[idc].pb(u);

    for(ll &v : g[u]) {
        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    scanf("%s", s+1);
    ll len = strlen(s+1);

    for(ll i = 2; i <= len; i++) {

        if(!vis[i]) {

            for(ll j = i+i; j <= len; j += i) {
                vis[j] = 1;

                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    ms(vis, 0);
    for1(i, len) {
        ll now = s[i] - 'a';
        cnt[now]++;
    }

    for0(i, 26) lst.insert(mp(cnt[i], i));

    for1(i, len) {
        if(vis[i]) continue;

        idc++;
        dfs(i);
    }

    bool ok = 1;
    for(ll id = 1; id <= idc; id++) {

        auto it = lst.lower_bound(mp(comp[id].size(), 0));

        if(it == lst.end()) {
            ok = 0;
            break;
        }

        char ch = it->second + 'a';

        for(ll &u: comp[id]) s[u] = ch;

        pll p = *it;
        lst.erase(it);

        p.first -= comp[id].size();
        lst.insert(p);
    }

    if(!ok) cout << "NO" << EL;
    else cout << "YES" << EL << (s+1) << EL;

    return 0;
}