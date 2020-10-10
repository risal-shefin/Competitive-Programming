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

const ll sz = 1e3 + 10;
char grid[sz][sz];
ll n, m;
bool row[sz], col[sz];

bool valid()
{
    for1(i, n) {
        ll cnt = 0, last = 0;
        for1(j, m) {
            if(grid[i][j] == '#') {
                if(last == 0) cnt++;
                last = 1;
            }
            else
                last = 0;
        }
        if(cnt > 1) return 0;
        row[i] = cnt;
    }

    for1(j, m) {
        ll cnt = 0, last = 0;
        for1(i, n) {
            if(grid[i][j] == '#') {
                if(last == 0) cnt++;
                last = 1;
            }
            else
                last = 0;
        }
        if(cnt > 1) return 0;
        col[j] = cnt;
    }
    return 1;
}

bool putExtra()
{
    for1(i, n) {
        if(row[i]) continue;

        bool pos = 0;
        for1(j, m) {
            if(!col[j]) {
                pos = 1;
                break;
            }
        }
        if(pos == 0) return 0;
    }

    for1(j, m) {
        if(col[j]) continue;

        bool pos = 0;
        for1(i, n) {
            if(!row[i]) {
                pos = 1;
                break;
            }
        }
        if(pos == 0) return 0;
    }
    return 1;
}

bool vis[sz][sz];

void dfs(ll r, ll c)
{
    if(r < 1 || c < 1 || r > n || c > m || vis[r][c] || grid[r][c] == '.') return;

    vis[r][c] = 1;
    dfs(r+1, c), dfs(r-1, c);
    dfs(r, c+1), dfs(r, c-1);
}

int main()
{
    cin >> n >> m;
    for1(i, n) scanf("%s", grid[i]+1);

    if(!valid() || !putExtra()) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for1(i, n) {
        for1(j, m) {
            if(!vis[i][j] && grid[i][j] == '#') {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}