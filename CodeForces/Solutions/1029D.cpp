#include <bits/stdc++.h>
using namespace std;

#define ll long long

map <ll, ll> cnt[12];

ll ara[200009], ln[200009];

int main()

{
    ll n, k;
    cin >> n >> k;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        ll tmp = ara[i];
        ll len = 0;
        while(tmp != 0) {
            tmp /= 10;
            len++;
        }

        ll rem = ara[i] % k;
        ln[i] = len;
        cnt[len][rem]++;
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {

        ll need = ara[i] % k;
        for(ll j = 1; j <= 10; j++) {
            need = (need * 10) % k;

            if(need > 0) {
                ans += cnt[j][k - need];
                if( (k - need) == ara[i] % k && j == ln[i])
                    ans--;
            }
            else {
                ans += cnt[j][0];
                if(0 == ara[i] % k && j == ln[i])
                    ans--;
            }

            //cout << j << "  " << need << "  " << cnt[j][need] << endl;
        }

        //cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}