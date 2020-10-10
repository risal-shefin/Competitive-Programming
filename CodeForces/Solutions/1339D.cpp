#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e5 + 10;
vector <ll> g[sz];
ll now = 0, mn = 0;
bitset <10*sz> tot;

void dfs(ll u, ll p, ll xr, ll lv)
{
    bool leaf = 0;
    for(ll v : g[u]) {
        if(v == p)
            continue;

        if(g[v].size() != 1) {
            now++;
            tot[now] = 1;
            dfs(v, u, xr^1, lv+1);
        }
        else {
            if( (xr^1) != 0)
                mn = max(mn, 3LL);
            else
                mn = max(mn, 1LL);

            leaf = 1;
        }
    }

    if(leaf && lv > 1) {
        now++;
        tot[now] = 1;
    }
}

int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    ll leaf;
    for1(i, n) {
        if(g[i].size() == 1) {
            leaf = i;
            break;
        }
    }

    dfs(leaf, -1, 0, 0);

    ll mx = tot.count();

    cout << mn << " " << mx << endl;

    return 0;
}