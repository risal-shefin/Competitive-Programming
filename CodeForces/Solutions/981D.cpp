#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll k, n, ara[55], cs[55], dp[55][55];

ll check(ll msk, ll pos, ll part)

{
    if(pos > n)
        return part > k;
    if(part > k)
        return 0;

    ll &ret = dp[pos][part];
    if(ret != -1)
        return ret;

    ll rt = 0;
    for(ll i = pos; i <= n; i++) {
        ll sm = cs[i] - cs[pos - 1];
        if( (sm & msk) == msk)
            rt |= check(msk, i + 1, part + 1);
    }

    return ret = rt;

}

int main()

{
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        cin >> ara[i];

    for(ll i = 1; i <= n; i++)
        cs[i] = ara[i] + cs[i - 1];

    ll ans = 0;
    for(ll i = 55; i >= 0; i--) {
        memset(dp, -1, sizeof(dp));
        if(check(ans | (1LL << i), 1, 1) )
            ans |= (1LL << i);
    }

    cout << ans << endl;

    return 0;
}