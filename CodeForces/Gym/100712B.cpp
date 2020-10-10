#include <bits/stdc++.h>
using namespace std;

#define ll long long
char grid[1009];
ll cum[3][1009], draw[3][1009];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(cum, 0, sizeof(cum));
        memset(draw, 0, sizeof(draw));
        ll n;
        scanf("%lld", &n);
        scanf("%s", grid + 1);

        for(ll i = 1; i <= n; i++) {
            if(grid[i] == 'S') {
                cum[0][i] = 1;
                draw[2][i] = 1;
            }
            else if(grid[i] == 'R') {
                cum[1][i] = 1;
                draw[0][i] = 1;
            }
            else {
                cum[2][i] = 1;
                draw[1][i] = 1;
            }

            cum[0][i] += cum[0][i - 1];
            cum[1][i] += cum[1][i - 1];
            cum[2][i] += cum[2][i - 1];

            draw[0][i] += draw[0][i - 1];
            draw[1][i] += draw[1][i - 1];
            draw[2][i] += draw[2][i - 1];
        }

        ll cnt = 0;
        //cout << cum[1][3] << endl;

        for(ll i = 0; i <= n; i++) {
            for(ll j = 0; j <= n; j++) {
                if(i + j > n)
                    break;
                ll k = n - (i + j);
                ll tot = cum[0][i] + (cum[1][i + j] - cum[1][i]) + (cum[2][n] - cum[2][i + j]);
                ll tot2 = draw[0][i] + (draw[1][i + j] - draw[1][i]) + (draw[2][n] - draw[2][i + j]);
                ll rev = n - (tot + tot2);
                //cout << i << " " << "  " << j << "  " << k << "  " << tot << "  " << rev << " " << endl;
                if(tot > rev)
                    cnt++;
            }
        }

        printf("%lld\n", cnt);
    }
    return 0;
}