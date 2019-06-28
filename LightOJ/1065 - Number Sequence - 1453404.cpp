#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, mo;
ll MOD;
ll MOD2;   /// Only when (MOD * MOD) fits into long long
#define row 2
#define col 2
struct MatExpo
{
    ll exponents[64][row][col];
    ll ident[row][col] = { {1, 0}, {0, 1} };  /// Identity Matrix
    ll result[row][col], mat[row][col];
      MatExpo() {
          /// Creating Base Matrix
        ll base[row][col] = { {1, 1}, {1, 0} };
        memcpy(exponents[0], base, sizeof(base));
          /// Calculating all exponents
        for(ll p = 1; p < 62; p++) {
              for(ll i = 0; i < row; i++) {
                for(ll j = 0; j < col; j++) {
                    ll tmp = 0;
                    for(ll k = 0; k < col; k++) {
                        tmp += exponents[p - 1][i][k] * exponents[p - 1][k][j];
                        while(tmp >= MOD2) /// Taking modulo MOD2 is easy, because we can do it by subtraction
                            tmp -= MOD2;
                    }
                    exponents[p][i][j] = tmp % MOD;
                }
            }
        }
      }
      ll ans(ll m) {
          /// Return from base case
        if(m == 0)
            return a;
        else if(m == 1)
            return b;
          memcpy(mat, ident, sizeof(ident));
        ll n = m - 1;   /// Here, (n - 1)th power of base matrix represents the nth term
        for(ll p = 60; p >= 0; p--) {
            if((n >> p) & 1) {
                  for(ll i = 0; i < row; i++) {
                    for(ll j = 0; j < col; j++) {
                        ll tmp = 0;
                        for(ll k = 0; k < col; k++) {
                            tmp += mat[i][k] * exponents[p][k][j];
                            while(tmp >= MOD2) /// Taking modulo MOD2 is easy, because we can do it by subtraction
                                tmp -= MOD2;
                        }
                        result[i][j] = tmp % MOD;
                    }
                }
                  memcpy(mat, result, sizeof(result));
            }
          }
          return (result[0][0] * b + result[0][1] * a) % MOD;
    }
};
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &mo);
          if(mo == 1) MOD = 10;
        else if(mo == 2) MOD = 100;
        else if(mo == 3) MOD = 1000;
        else MOD = 10000;
          MOD2 = MOD * MOD;
          MatExpo ex = MatExpo();
        printf("Case %lld: %lld\n", ++cs, ex.ans(n));
    }
      return 0;
}
 
