#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define Set(n, pos) n |= ((ll)1 << (pos))
#define check(n, pos) (n >> (pos)) & (ll)1
const int siz = 50002;
char y[siz], x[siz];
ll M[27][siz / 63 + 1], M2[30][siz / 63 + 1], L[siz][siz / 63 + 1], tmp[siz / 63 + 1], indx;
ll clr, clr2, c;
int main()
 {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     register int i, j, ans = 0;
    clr = ((ll)1 << 63) - 1;
     cin >> (y + 1) >> (x + 1);
    ll n = strlen(y + 1), m = strlen(x + 1);
     ll lim = m / 63, last = m % 63;
    clr2 = ((ll)1 << (last + 1)) - 1;
    for(i = 1; i <= m; i++) {
        indx = x[i] - 'a';
        Set(M[indx][i / 63], i % 63);
    }
     for(i = 0; i < 26; i++) {
        for(j = 0; j <= lim; j++) {
            M2[i][j] = ~M[i][j];
             if(j == 0) M2[i][j] &= (clr ^ (ll)1);
            if(j == lim) M2[i][j] &= clr2;
            else M2[i][j] &= clr;
        }
    }
     for(i = 0; i <= lim; i++) {
        L[0][i] = clr;
         if(i == 0) L[0][i] &= (clr ^ (ll)1);
        if(i == lim) L[0][i] &= clr2;
    }
     for(j = 1; j <= n; j++) {
        indx = y[j] - 'a';
        for(i = 0; i <= lim; i++)
            tmp[i] = L[j-1][i] & M[indx][i];
         c = 0;
        for(i = 0; i <= lim; i++) {
            L[j][i] = L[j - 1][i] + tmp[i] + c;
            if(i == lim) {
                if(check(L[j][i], last + 1) == 1) c = 1;
                else c = 0;
                L[j][i] &= clr2;
            }
            else {
                if(check(L[j][i], 63) == 1) c = 1;
                else c = 0;
                L[j][i] &= clr;
            }
        }
         for(i = 0; i <= lim; i++)
            L[j][i] |= L[j - 1][i] & M2[indx][i];
         ans += c;
    }
     cout << ans << endl;
     return 0;
}
