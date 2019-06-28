#include <bits/stdc++.h>
using namespace std;
#define ll long long
char grid[5][100];
int main()
{
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= 4; i++) {
        for(ll j = 1; j <= n; j++)
            grid[i][j] = '.';
    }
    ll mid = n / 2 + 1;
    printf("YES\n");
    if(k % 2 != 0) {
        grid[2][mid] = '#';
        k--;
        ll l = mid - 1, r = mid + 1;
        if(k <= n - 3) {
            //cout << 5;
            while(k != 0) {
                grid[2][l] = '#';
                grid[2][r] = '#';
                k -= 2;
                l--, r++;
            }
        }
        else {
            while(l > 1) {
                grid[2][l] = '#';
                grid[2][r] = '#';
                k -= 2;
                l--, r++;
            }
            l = 2, r = n - 1;
            while(k != 0) {
                grid[3][l] = '#';
                grid[3][r] = '#';
                k -= 2;
                l++, r--;
            }
        }
    }
    else {
        if(k <= n - 2) {
            ll l = 2, r = n - 1;
            while(k != 0) {
                grid[2][l] = '#';
                grid[2][r] = '#';
                k -= 2;
                l++, r--;
            }
        }
        else {
            ll l = 2, r = n - 1;
            while(l < mid) {
                grid[2][l] = '#';
                grid[2][r] = '#';
                k -= 2;
                l++, r--;
            }
            l = 2, r = n - 1;
            while(l < mid && k != 0) {
                grid[3][l] = '#';
                grid[3][r] = '#';
                k -= 2;
                l++, r--;
            }
            if(k == 2) {
                grid[2][mid] = '#';
                grid[3][mid] = '#';
            }
        }
    }
    for(ll i = 1; i <= 4; i++) {
        for(ll j = 1; j <= n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
