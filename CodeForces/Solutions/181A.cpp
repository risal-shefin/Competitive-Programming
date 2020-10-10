#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[110][110];
pair <ll, ll> city[3];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%s", grid[i] + 1);

    ll dif, eka, indx = -1;
    for(ll i = 1; i <= n; i++) {
        ll cnt = 0;
        for(ll j = 1; j <= m; j++) {
            if(grid[i][j] == '*') {
                cnt++;
                city[++indx] = make_pair(i, j);
            }
        }

        if(cnt == 1)
            eka = indx;
    }

    for(ll i = 0; i <= indx; i++) {
        if(eka == i)
            continue;

        //cout << city[eka].second << endl;
        if(city[i].second == city[eka].second) {
            for(ll j = 0; j <= indx; j++) {
                if(i == j || j == eka)
                    continue;

                dif = city[i].second - city[j].second;

                cout << city[eka].first << " " << city[eka].second - dif << endl;
                return 0;
            }
        }
    }

    return 0;
}