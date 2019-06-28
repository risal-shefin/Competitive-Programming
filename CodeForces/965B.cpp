#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2e18
char grid[110][110];
ll cnt[110][110];
int main()
{
    ll n, k2;
    cin >> n >> k2;
    for(ll i = 1; i <= n; i++)
        scanf(" %s", grid[i] + 1);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            //cout << grid[i][j] << "  ";
            if(grid[i][j] == '#')
                continue;
            bool test = 1;
            for(ll k = j, m = 1; m <= k2; m++, k++) {
                if(k > n) {
                    test = 0;
                    break;
                }
                if(grid[i][k] == '#') {
                    test = 0;
                    break;
                }
            }
            if(test) {
                for(ll k = j, m = 1; m <= k2; m++, k++) {
                    cnt[i][k]++;
                }
            }
            test = 1;
            for(ll k = i, m = 1; m <= k2; m++, k++)  {
                if(k > n) {
                    test = 0;
                    break;
                }
                if(grid[k][j] == '#') {
                    test = 0;
                    break;
                }
            }
            if(test) {
                for(ll k = i, m = 1; m <= k2; k++, m++) {
                    cnt[k][j]++;
                }
            }
        }
        //cout << endl;
    }
    ll row, col, mx = -1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            if(mx < cnt[i][j]) {
                row = i;
                col = j;
                mx = cnt[i][j];
            }
        }
    }
    //cout << cnt[6][1] << endl;
    cout << row << " " << col << endl;
    return 0;
}
