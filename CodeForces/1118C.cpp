#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[1009], cnt[1009];;
ll check[1009], num[1009], mat[30][30];
int main()
{
    ll n;
    cin >> n;
    ll tot = n * n, indx = 0;
    for(ll i = 1; i <= tot; i++) {
        scanf("%lld", &ara[i]);
        cnt[ ara[i] ]++;
        if(check[ ara[i] ] == 0) {
            check[ ara[i] ] = 1;
            num[indx++] = ara[i];
        }
    }
    if(n % 2 == 0) {
        for(ll i = 0; i < indx; i++) {
            if(cnt[ num[i] ] % 4 != 0) {
                //cout << num[i] << "  " << cnt[num[i]] << endl;
                cout << "NO" << endl;
                return 0;
            }
        }
        ll half = n / 2;
        for(ll i = 0, r = n - 1; i < half; i++, r--) {
            for(ll j = 0, c = n - 1; j < half; j++, c--) {
                for(ll k = 0; k < indx; k++) {
                    if(cnt[num[k]] < 4)
                        continue;
                    mat[i][j] = mat[i][c] = mat[r][j] = mat[r][c] = num[k];
                    cnt[num[k]] -= 4;
                    break;
                }
            }
        }
    }
    else {
        ll od = 0;;
        for(ll i = 0; i < indx; i++) {
            if(cnt[num[i]] % 2 != 0)
                od++;
        }
        if(od > 1) {
            cout << "NO" << endl;
            return 0;
        }
        ll half = n / 2;
        for(ll i = 0, r = n - 1; i < half; i++, r--) {
            for(ll j = 0, c = n - 1; j < half; j++, c--) {
                bool chk = 1;
                for(ll k = 0; k < indx; k++) {
                    if(cnt[num[k]] < 4)
                        continue;
                    mat[i][j] = mat[i][c] = mat[r][j] = mat[r][c] = num[k];
                    cnt[num[k]] -= 4;
                    chk = 0;
                    break;
                }
                if(chk) {
                    cout << "NO" << endl;;
                    return 0;
                }
            }
        }
        for(ll i = 0, r = n - 1; i < half; i++, r--) {
            bool chk = 1;
            for(ll k = 0; k < indx; k++) {
                if(cnt[num[k]] < 2)
                    continue;
                mat[i][half] = mat[r][half] = num[k];
                cnt[ num[k] ] -= 2;
                chk = 0;
                break;
            }
            if(chk) {
                cout << "NO" << endl;;
                return 0;
            }
        }
        for(ll i = 0, r = n - 1; i < half; i++, r--) {
            bool chk = 1;
            for(ll k = 0; k < indx; k++) {
                if(cnt[num[k]] < 2)
                    continue;
                mat[half][i] = mat[half][r] = num[k];
                cnt[ num[k] ] -= 2;
                chk = 0;
                break;
            }
            if(chk) {
                cout << "NO" << endl;;
                return 0;
            }
        }
        bool chk = 1;
        for(ll i = 0; i < indx; i++) {
            if(cnt[ num[i] ] < 1)
                continue;
            chk = 0;
            mat[half][half] = num[i];
            break;
        }
            if(chk) {
                cout << "NO" << endl;;
                return 0;
            }
    }
    cout << "YES" << endl;;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(j != 0)
                printf(" ");
            printf("%lld", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
