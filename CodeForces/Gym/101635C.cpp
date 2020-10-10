#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll sz = 1 << 8;
const ll MOD = 1e9;
ll w[sz], lim, n, m, n2;

ll solve2(ll msk, ll pos)

{
    if(pos == n)
        return 1;

    if((msk >> pos) & 1)
        return solve2(msk, pos + 1) % MOD;

    ll ret = solve2(msk, pos + 1) % MOD;
    if(pos + 1 < n) {
        if(!( (msk >> (pos + 1)) & 1) )
            ret = (ret + solve2(msk, pos + 2)) % MOD;
    }

    return ret;
}

const ll MOD2 = MOD * MOD;   /// Only when (MOD * MOD) fits into long long
#define row 256
#define col 256

ll ident[row][col]; /// Identity Matrix
ll base[row][col];
ll exponents[64][row][col];
ll result[row][col], mat[row][col];


struct MatExpo

{
    MatExpo() {

        /// Creating Base Matrix
        memcpy(exponents[0], base, sizeof(base));

        /// Calculating all exponents
        for(ll p = 1; p <= n2; p++) {

            for(ll i = 0; i < lim; i++) {
                for(ll j = 0; j < lim; j++) {
                    ll tmp = 0;
                    for(ll k = 0; k < lim; k++) {
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

        memcpy(mat, ident, sizeof(ident));
        ll n = m - 1;   /// Here, (n - 1)th power of base matrix represents the nth term
        for(ll p = n2; p >= 0; p--) {
            if((n >> p) & 1) {

                for(ll i = 0; i < lim; i++) {
                    for(ll j = 0; j < lim; j++) {
                        ll tmp = 0;
                        for(ll k = 0; k < lim; k++) {
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

        ll ret = 0;
        for(ll i = 0; i < lim; i++) {
            ret = (ret + result[0][i] * w[i]) % MOD;
//            cout << bitset <2>(i) << "  " << (result[0][i] * w[i]) << "   " << w[i] << endl;
        }
        return ret;
    }

};

int main()

{
    cin >> n >> m;
    lim = (1 << n);
    for(ll i = 0; i < lim; i++) {
        w[i] = solve2(i, 0);
    }

    if(m == 1) {
        cout << w[0] << endl;
        return 0;
    }

    for(ll i = 0; i < lim; i++)
        ident[i][i] = 1;

    ll msk = 1;
    for(ll i = 0; i < lim; i++) {
        for(ll j = 0; j < lim; j++) {
            if(i == 0)
                base[i][j] = w[j];
            else {
                if(j == 0) {
                    base[i][j] = w[msk];
                    continue;
                }

                bool flag = 0;
                for(ll k = 0; k < n; k++) {
                    ll bt1 = (msk >> k) & 1;
                    ll bt2 = (j >> k) & 1;

                    if(bt1 == bt2 && bt1 == 1) {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    continue;

                ll nmsk = msk | j;
                base[i][j] = w[nmsk];
            }
        }
        if(i > 0)
            msk++;
    }

    for(n2 = 1; ; n2++) {
        if((1LL << n2) > m)
            break;
    }
    MatExpo ex = MatExpo();
    cout << ex.ans(m) << endl;

    return 0;
}