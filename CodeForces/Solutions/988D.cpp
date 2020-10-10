#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(x) scanf("%lld", &x)

ll ara[200009], n, ans[3];

ll pwr[40];
map <ll, bool> chk;

int main()

{
    //ios::sync_with_stdio(false);

    ll gun = 1;
    for(ll i = 0; i <= 35; i++) {
        pwr[i] = gun;
        gun *= 2;
    }

    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        chk[ ara[i] ] = 1;
    }

    sort(ara + 1, ara + n + 1);

    ll len = 1;
    for(ll i = 1; i <= n; i++) {
        if(len == 3)
            break;
        for(ll j = 0; j <= 32; j++) {
            ll tmp1 = ara[i] + pwr[j];
            ll tmp2 = tmp1 + pwr[j];

            if(chk.find(tmp1) != chk.end() && chk.find(tmp2) != chk.end() && len < 3) {
                len = 3;
                ans[0] = ara[i];
                ans[1] = tmp1;
                ans[2] = tmp2;
                break;
            }

            else if(chk.find(tmp1) != chk.end() && len < 2) {
                len = 2;
                ans[0] = ara[i];
                ans[1] = tmp1;
            }
        }
    }

    if(len == 1)
        ans[0] = ara[1];

    cout << len << endl;
    for(ll i = 0; i < len; i++) {
        if(i != 0)
            cout << " ";
        printf("%lld", ans[i]);
    }

    cout << endl;

    return 0;
}