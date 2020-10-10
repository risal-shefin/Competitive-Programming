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
bool vis[sz][sz], mark[sz][sz];

ll n, m;

void dfs(ll r, ll c)
{
    if(r < 1 || c < 1 || r > n || c > m || vis[r][c] || mark[r][c] || grid[r][c] == '#')
        return;

    vis[r][c] = 1;
    dfs(r+1, c), dfs(r-1, c);
    dfs(r, c+1), dfs(r, c-1);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(m);

        for1(i, n) scanf("%s", grid[i]+1);

        ll g = 0;
        for1(i, n) {
            for1(j, m) {
                if(grid[i][j] == 'G')
                    g++;
            }
        }

        if(g == 0) {
            pf("Yes\n");
            continue;
        }

        for1(i, n) {
            for1(j, m) {
                if(grid[i][j] == 'B') {
                    mark[i+1][j] = mark[i-1][j] = 1;
                    mark[i][j+1] = mark[i][j-1] = 1;
                    mark[i][j] = 1;
                }
            }
        }

        dfs(n, m);

        bool ok = 1;
        for1(i, n) {
            for1(j, m) {
                if(grid[i][j] == 'G' && !vis[i][j])
                    ok = 0;
            }
        }

        if(ok) pf("Yes\n");
        else pf("No\n");

        ms(vis, 0);
        ms(mark, 0);
    }

    return 0;
}