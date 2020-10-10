#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, ara[200009], cum[200009], cum2[200009];

bool isPos(ll indx)

{
    ll lo = indx + 1, hi = n;
    //cout << lo << "  " << hi << endl;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        //cout << indx << "  "  << mid << "  " << cum2[mid] << endl;
        if(cum2[mid] == cum[indx])
            return 1;
        else if(cum2[mid] > cum[indx])
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return 0;
}

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        cum[i] = ara[i] + cum[i - 1];
    }

    for(ll i = n; i >= 1; i--)
        cum2[i] = ara[i] + cum2[i + 1];


    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        if(isPos(i) ) {
            ans = max(ans, cum[i]);
            //cout << ans << endl;
        }
    }

    cout << ans << endl;

    return 0;
}