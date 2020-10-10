#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()

{
    ll n;
    cin >> n;
    ll lo = 1, hi = n, ans;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll dv = n / mid;
        if(dv > 1) {
            lo = mid + 1;
        }
        else {
            ans = mid;
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}