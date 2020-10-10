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

const ll sz = 35;
bool vis[sz][sz];
ll mat[sz][sz], cz[100], co[100], last, n, m;

void dfs(ll r, ll c, ll lv)
{
    if(r < 1 || c < 1 || r > n || c > m || vis[r][c])
        return;

    vis[r][c] = 1;
    if(mat[r][c] == 1) co[lv]++;
    else cz[lv]++;

    last = max(last, lv);
    dfs(r+1, c, lv+1), dfs(r, c+1, lv+1);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(m);

        for1(i, n) {
            for1(j, m) {
                sl(mat[i][j]);
            }
        }

        last = 0;
        dfs(1, 1, 1);

        ll ans = 0;
        for(ll i = 1, j = last; i <= last/2; i++, j--) {
            ll one = co[i] + co[j];
            ll zero = cz[i] + cz[j];

            ans += min(one, zero);
        }

        pf("%lld\n", ans);

        ms(vis, 0), ms(cz, 0), ms(co, 0);
    }

    return 0;
}