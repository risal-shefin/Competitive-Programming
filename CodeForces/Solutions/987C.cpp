#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18

struct node {
    ll s;
    ll c;
    ll id;
} ara[3009];

ll dp[3009][4];

ll solve(ll indx, ll cnt, ll val)

{
    if(cnt < 1)
        return 0;
    if(indx < 0)
        return 1e18;

    if(dp[indx][cnt] != -1)
        return dp[indx][cnt];

    ll ret = 1e18, tmp = 1e18;
    for(ll i = indx; i >= 0; i--) {
        if(ara[i].s < val)
            tmp = ara[i].c + solve(i - 1, cnt - 1, ara[i].s);

        if(tmp != 1e18)
            ret = min(ret, tmp);
    }

    return dp[indx][cnt] = ret;
}

int main()

{
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i].s);
    }

    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i].c);
        ara[i].id = i;
    }

    ll ans = 1e18;
    for(ll i = n - 1; i >= 0; i--) {
        ans = min(ans, ara[i].c + solve(i - 1, 2, ara[i].s) );
        //cout << ans << " " << i << endl;
    }

    if(ans == 1e18)
        cout << "-1" << endl;
    else
        cout << ans << endl;

    return 0;
}