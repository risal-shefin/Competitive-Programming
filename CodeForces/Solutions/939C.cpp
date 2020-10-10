#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll cumsum[100009];

int main()

{
    ll n, counter = -1;
    cin >> n;
    vector <ll> v;
    ll ara[n + 5];
    for(ll i = 1; i <= n; i++) {
        scanf("%I64d", &ara[i]);
        cumsum[i] = ara[i] + cumsum[i - 1];
    }

    ll start, stop, indx;
    cin >> start >> stop;
    ll dif = stop - start;

    ll mx = INT_MIN;
    for(ll i = 1; i <= n; i++) {
        ll sum;
        if( i + (dif - 1) <= n)
            sum = cumsum[i + (dif - 1)] - cumsum[i - 1];
        else {
            ll tmp1 = cumsum[n] - cumsum[i - 1];
            ll tmp2 = cumsum[i + dif - 1 - n] - cumsum[0];
            sum = tmp1 + tmp2;
        }

        if(mx < sum) {
            //cout << sum << endl;
            mx = sum;
            indx = i;
        }

    }

    for(ll i = 1; i <= n; i++) {
         ll sum;
        if( i + (dif - 1) <= n)
            sum = cumsum[i + (dif - 1)] - cumsum[i - 1];
        else {
            ll tmp1 = cumsum[n] - cumsum[i - 1];
            ll tmp2 = cumsum[i + dif - 1 - n] - cumsum[0];
            sum = tmp1 + tmp2;
        }

        if(mx == sum) {
            //cout << mx << endl;
            v.push_back(i);
        }

    }

    //cout << indx << endl;

    ll ans = INT_MAX;
    for(ll i = 0; i < v.size(); i++) {
        ll tmp = (start - (v[i] - 1));
        if(tmp < 0)
            tmp =  (tmp + n) % n;

        if(tmp == 0)
            tmp = n;

        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}