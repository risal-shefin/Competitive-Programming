#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, state = 0, cnt = 0;
    cin >> n;
    char ara[n + 5][n + 5];
    for(ll i = 1; i <= n; i++) {
        state ^= 1;
        for(ll j = 1; j <= n; j++) {
            if(state == 1) {
                if(j % 2 != 0) {
                    ara[i][j] = 'C';
                    cnt++;
                }
                else
                    ara[i][j] = '.';
            }
            else {
                if(j % 2 == 0) {
                    ara[i][j] = 'C';
                    cnt++;
                }
                else
                    ara[i][j] = '.';
            }
        }
    }
    cout << cnt << endl;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            printf("%c", ara[i][j]);
        }
        printf("\n");
    }
    return 0;
}
