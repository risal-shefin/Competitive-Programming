#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll m, ans = -1;
    cin >> m;
    ll lo = 1, hi = 1e18;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(ll i = 2; ; i++) {
            if(mid / (i * i * i) == 0)
                break;
            cnt += ( mid / (i * i * i) );
        }
        if(cnt == m) {
            ans = mid;
            hi = mid - 1;
        }
        else if(cnt < m)
            lo = mid + 1;
        else if(cnt > m)
            hi = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
