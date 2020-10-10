#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll grid[22][22], mid, n, m, k, ans = 0;
unordered_map <ll, ll> cnt[22][22];

void solve(ll r, ll c, ll step, ll xr)

{
    if(r < 0 || r > n || c < 0 || c > m)
        return;
    if(step == mid) {
        cnt[r][c][xr]++;
        return;
    }

    solve(r + 1, c, step + 1, xr ^ grid[r + 1][c]);
    solve(r, c + 1, step + 1, xr ^ grid[r][c + 1]);
}

void solve2(ll r, ll c, ll step, ll xr)

{
    if(r < 0 || r > n || c < 0 || c > m)
        return;
    if(step == mid) {
        ll need = k ^ xr ^ grid[r][c];
        ans += cnt[r][c][need];
        return;
    }

    solve2(r - 1, c, step + 1, xr ^ grid[r - 1][c]);
    solve2(r, c - 1, step + 1, xr ^ grid[r][c - 1]);
}

int main()

{
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            scanf("%lld", &grid[i][j]);
        }
    }

    if(n == 1 && m == 1) {
        if(grid[1][1] == k) {
            printf("1\n");
        }
        else
            printf("0\n");

        return 0;
    }

    mid = (n + m - 2) / 2;
    solve(1, 1, 0, grid[1][1]);
    if((n + m - 2) & 1)
        mid++;
    solve2(n, m, 0, grid[n][m]);

    cout << ans << endl;

    return 0;
}