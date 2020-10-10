#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

ll ara[200009], lav[200009], cum[200009];

int main()

{
    ll n, q, mns = 0;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i <= q; i++)
        scanf("%lld", &lav[i]);

    for(ll i = 1; i <= n; i++) {
        cum[i] = ara[i] + cum[i - 1];
    }

    ll lo = 1;
    for(ll i = 1; i <= q; i++) {
        ll pwr = lav[i];

        //cout << "   " << mns << endl;
        ll hi = n, ansi = 0;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(cum[mid] - mns > pwr) {
                hi = mid - 1;
            }
            else if(cum[mid] - mns <= pwr) {
                lo = mid + 1;
                ansi = mid;
            }
        }

        //cout << "   " << ansi << endl;
        ll alive = n - ansi;
        if(ansi == 0) {
            alive = n - lo + 1;
        }
        mns = pwr + mns;
        lo = ansi + 1;
        if(alive == 0) {
            mns = 0;
            alive = n;
            lo = 1;
        }
        printf("%lld\n", alive);
    }

    return 0;
}