#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[5009], dp[5009][5009];
ll n, k;

ll solve(ll pos, ll t)

{
    if(pos > n)
        return 0;
    if(t > k)
        return 0;
    ll &ret = dp[pos][t];
    if(ret != -1)
        return ret;

    ll lo = pos, hi = n, last;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(ara[mid] > ara[pos] + 5)
            hi = mid - 1;
        else {
            last = mid;
            lo = mid + 1;
        }
    }

    ll rt = last - pos + 1;

    rt = max(rt + solve(last + 1, t + 1), solve(pos + 1, t));

    return ret = rt;
}

int main()

{
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1);

    cout << solve(1, 1) << endl;

    return 0;
}