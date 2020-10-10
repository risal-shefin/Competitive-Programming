#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[200009];

ll solve(ll pos, ll n)

{
    ll lo = pos, hi = n, rt = pos;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(ara[mid] > ara[pos] + 5) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
            rt = mid;
        }
    }

    return rt;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1);

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll tmp = solve(i, n) - i + 1;
        //cout << i << "  " << tmp << endl;
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}