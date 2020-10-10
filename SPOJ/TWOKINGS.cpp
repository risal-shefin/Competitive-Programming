#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[12][12];
bool vis[12][12];
ll n, m;
ll row[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll col[] = {0, 0, 1, -1, -1, 1, -1, 1};

void dfs(ll r, ll c, char ch)

{
    for(ll i = 0; i < 8; i++) {
        ll tr = r + row[i];
        ll tc = c + col[i];

        if(tr > 0 && tr <= n && tc > 0 && tc <= m && vis[tr][tc] == 0 && grid[tr][tc] == ch) {
            vis[tr][tc] = 1;
            dfs(tr, tc, ch);
        }
    }
}

int main()

{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= n; i++)
            scanf("%s", grid[i] + 1);

        ll cnt = 0, cnt2 = 0;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                if(vis[i][j])
                    continue;
                if(grid[i][j] == 'X')
                    cnt++;
                else
                    cnt2++;
                dfs(i, j, grid[i][j]);
            }
        }

        if(cnt >= cnt2)
            printf("X\n");
        else
            printf("O\n");
    }

    return 0;
}

