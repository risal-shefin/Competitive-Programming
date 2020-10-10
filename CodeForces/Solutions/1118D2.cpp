#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[200005], n, m;

bool solve(ll d)

{
    ll i = 1, rnd = 1, sum = 0;
    while(1) {

        for(ll id = 1; id <= d && i <= n; i++, id++)
            sum += max(0LL, ara[i] - rnd + 1);

        if(sum >= m)
            return 1;
        rnd++;
        if(i > n)
            break;
    }

    return 0;
}

int main()

{
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1, greater <ll>());
    ll lo = 1, hi = n, ans = -1;

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        bool chk = solve(mid);

        if(chk) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}