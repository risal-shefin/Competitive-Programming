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

const ll sz = 55;
char grid[sz][sz];
ll n, m, vis[sz][sz], lev[sz][sz], cyc;

void dfs(ll r, ll c, ll lv, char ch)
{
    if(r < 1 || c < 1 || r > n || c > m || vis[r][c] == 2 || grid[r][c] != ch)
        return;

    if(vis[r][c] == 1) {
        ll len = lv - lev[r][c];
        cyc = max(cyc, len);
        return;
    }

    vis[r][c] = 1, lev[r][c] = lv;

    dfs(r, c+1, lv+1, ch), dfs(r, c-1, lv+1, ch);
    dfs(r-1, c, lv+1, ch), dfs(r+1, c, lv+1, ch);

    vis[r][c] = 2;
}

int main()
{
    cin >> n >> m;
    for1(i, n) scanf("%s", grid[i]+1);

    for1(i, n) {
        for1(j, m) {
            if(vis[i][j])
                continue;

            dfs(i, j, 1, grid[i][j]);
        }
    }

    if(cyc >= 4) cout << "Yes" << EL;
    else cout << "No" << EL;

    return 0;
}