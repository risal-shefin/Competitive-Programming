#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sl(val) scanf("%lld", &val)
#define inf 2e18

ll ara[100009], n, loc = 0;

bool isPos(ll k)

{
    ll len = -1, cnt = 0, counter = 0;
    for(ll i = 1; i <= n; i++) {
        if(ara[i] < k) {
            cnt++;
        }
        else {
            if(len > 0 && cnt > 0) {
                if(len != cnt)
                    return 0;
            }

            if(cnt != 0)
                counter++;
            len = cnt;
            cnt = 0;
        }
    }

    if(cnt != 0)
        counter++;

    if(!counter)
        return 0;

    loc = counter;
    return 1;
}

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    ll lo = 0, hi = 1e10, ans = -1, prv = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(isPos(mid)) {
            if(prv != -1) {
                if(prv > loc) {
                    lo = mid + 1;
                    continue;
                }
            }
            ans = mid;
            hi = mid - 1;
            prv = loc;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}