#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[200009], cnt[120];

int main()

{
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        ara[i] %= k;

        cnt[ ara[i] ]++;
    }

    ll ans = 0;
    for(ll i = 0; i < k; i++) {
        ll lagbe = k - i;
        if(i == 0)
            lagbe = 0;
        ll tmp = min(cnt[i], cnt[lagbe]);
        if(i == lagbe)
            tmp /= 2;

        cnt[lagbe] -= tmp;
        cnt[i] -= tmp;

        ans += (2 * tmp);

        //cout << i << "  " << tmp << endl;
    }

    cout << ans << endl;


    return 0;
}