#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[105][105];
ll row[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll col[] = {1, -1, 0, 0, -1, 1, -1, 1};

int main()

{
    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    bool chk = 1;
    ll num = 0, cnt = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(grid[i][j] == '*')
                continue;
            if(grid[i][j] == '.')
                num = 0;
            else {
                num = grid[i][j] - '0';
            }

            cnt = 0;

            for(ll k = 0; k < 8; k++) {
                ll tr = i + row[k];
                ll tc = j + col[k];

                if(tc < 1 || tr < 1 || tr > n || tc > m)
                    continue;

                if(grid[tr][tc] == '*')
                    cnt++;
            }

            if(cnt != num) {
                chk = 0;
                break;
            }
        }
    }

    if(chk)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}