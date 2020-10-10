#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll ara[20], tmp[20], mx = 0;
    for(ll i = 1; i <= 14; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i <= 14; i++) {

        if(ara[i] == 0)
            continue;

        for(ll j = 1; j <= 14; j++)
            tmp[j] = ara[j];

        tmp[i] = 0;
        ll dist = ara[i] / 14;

        for(ll j = 1; j <= 14; j++)
            tmp[j] += dist;

        ll rem = ara[i] % 14;
        ll start = i + 1;
        if(start > 14)
            start = 1;

        for(ll j = 1; j <= rem; j++, start++) {
            tmp[ start ]++;

            if(start == 14)
                start = 0;
        }

        ll cnt = 0;
        for(ll j = 1; j <= 14; j++) {
            if( tmp[j] % 2 == 0)
                cnt += tmp[j];
        }

        mx = max(mx, cnt);
    }

    cout << mx << endl;

    return 0;
}