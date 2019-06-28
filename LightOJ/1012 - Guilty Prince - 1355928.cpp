#include <bits/stdc++.h>
using namespace std;
#define ll long long
char grid[25][25];
ll r, c, sr, sc;
bitset <25> vis[25];
void dfs(ll i, ll j)
{
    if(i < 1 || j < 1 || i > r || j > c || grid[i][j] == '#')
        return;
    if(vis[i][j] == 1)
        return;
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        scanf("%lld %lld", &c, &r);
        for(ll i = 1; i <= r; i++) {
            for(ll j = 1; j <= c; j++) {
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == '@')
                    sr = i, sc = j;
            }
        }
          dfs(sr, sc);
          ll ans = 0;
        for(ll i = 1; i <= r; i++) {
            ans += vis[i].count();
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
          for(ll i = 1; i <= r; i++)
            vis[i].reset();
    }
      return 0;
}
 
