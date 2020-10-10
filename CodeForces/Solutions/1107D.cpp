#include <bits/stdc++.h>
using namespace std;

#define ll int

char todo[18][6] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int mat[5202][5202];
char inp[1500];

int main()

{
    ll n, pos;
    cin >> n;
    ll rw = n / 4;
    char ch;
    for(ll i = 1; i <= n; i++) {
        scanf("%s", inp);

        for(ll j = 0; j < rw; j++) {
            pos = inp[j] - '0';
            if(isalpha(inp[j]) )
                pos = inp[j] - 'A' + 10;

            for(ll k = j * 4 + 1, s = 0; s < 4; k++, s++)
                mat[i][k] = (todo[pos][s] - '0');
        }
    }

    ll lo = 1, hi = n, ans = 1, i, j;
    bool chk = 1;
    for(ll k = 1; k * k <= n; k++) {

        if(n % k != 0)
            continue;

        ll x = n / k, ni = 1, nj = 1;
        chk = 1;
        ll cnti = 0, cntj = 0;
        for(i = 1; i <= n; i++) {
            nj = 1;
            cntj = 0;

            cnti++;
            if(cnti > x) {
                cnti = 1;
                ni = i;
            }
            for(j = 1; j <= n; j++) {
                cntj++;
                if (cntj > x) {
                    cntj = 1;
                    nj = j;
                }

                if(mat[i][j] != mat[ni][nj]) {
                    chk = 0;
                    break;
                }
            }
            if(!chk)
                break;
        }

        if(chk) {
            ans = max(ans, x);
            break;
        }

        if(k * k == n)
            continue;

        x = k;
        chk = 1;
        cnti = 0, cntj = 0;
        ni = 1, nj = 1;
        for(i = 1; i <= n; i++) {
            nj = 1;
            cntj = 0;

            cnti++;
            if (cnti > x) {
                cnti = 1;
                ni = i;
            }
            for(j = 1; j <= n; j++) {
                cntj++;
                if (cntj > x) {
                    cntj = 1;
                    nj = j;
                }

                if(mat[i][j] != mat[ni][nj]) {
                    chk = 0;
                    break;
                }
            }
            if(!chk)
                break;
        }

        if(chk)
            ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}