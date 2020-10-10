#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solvemin(ll a1, ll a2, ll k1, ll k2, ll n)

{
    ll cnt2 = 0;
    while(n > 0 && cnt2 < k2 - 1) {
        n -= a2;
        cnt2++;
    }

    ll cnt1 = 0;
    while(n > 0 && cnt1 < k1 - 1) {
        n -= a1;
        cnt1++;
    }

    ll sum = 0;
    if(n > 0) {
        sum = min(a2, n);
        n -= sum;
    }
    if(n > 0) {
        sum += min(a1, n);
        n -= min(a1, n);
    }

    return sum;
}

ll solvemax(ll a1, ll a2, ll k1, ll k2, ll n)

{
    ll ret = 0;
    for(ll i = 1; i <= a1; i++) {
        n -= k1;
        if(n >= 0) {
            ret++;
        }
        else
            return ret;
    }
    for(ll i = 1; i <= a2; i++) {
        n -= k2;
        if(n >= 0) {
            ret++;
        }
        else
            return ret;
    }

    return ret;
}

int main()

{
    ll a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if(k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }

    ll ans1 = solvemin(a1, a2, k1, k2, n);
    ll ans2 = solvemax(a1, a2, k1, k2, n);

    cout << ans1 << " " << ans2 << endl;

    return 0;
}