#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[55][55];

int main()

{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;

    for(ll i = 1; i <= 50; i++) {
        for(ll j = 1; j <= 25; j++) {
            grid[i][j] = 'A';
        }

        for(ll j = 26; j <= 50; j++) {
            grid[i][j] = 'B';
        }
    }

    for(ll i = 1; i <= 50; i += 2) {
        for(ll j = 1; j < 25; j += 2) {
            if(b > 0) grid[i][j] = 'B', b--;
            else if(c > 0) grid[i][j] = 'C', c--;
            else if(d > 0) grid[i][j] = 'D', d--;
        }
    }

    for(ll i = 1; i <= 50; i += 2) {
        for(ll j = 27; j <= 50; j += 2) {
            if(a > 0) grid[i][j] = 'A', a--;
            else if(c > 0) grid[i][j] = 'C', c--;
            else if(d > 0) grid[i][j] = 'D', d--;
        }
    }

    cout << "50 50" << endl;
    for(ll i = 1; i <= 50; i++)
        cout << grid[i] + 1 << endl;

    return 0;
}