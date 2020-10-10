#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define mp make_pair
#define pb push_back
#define pll pair <ll, ll>

ll ara[109], k, dp[109][109], n;

ll solve(ll pos, ll now)

{
    if(now > k)
        return 0;
    if(pos > n)
        return -inf;

    ll &ret = dp[pos][now];
    if(ret != -1)
        return ret;

    ll mx = solve(pos + 1, now);
    mx = max(mx, ara[pos] + solve(pos + 1, now + 1));

    return ret = mx;
}

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    ll m;
    cin >> m;
    for(ll i = 1; i <= m; i++) {
        ll pos;
        scanf("%lld %lld", &k, &pos);

        memset(dp, -1, sizeof(dp));
        ll mx = solve(1, 1);
        dp[n+1][k+1] = 0;
        //cout << mx << endl;

        ll start =  1, ans;
        for(ll j = 1; j <= pos; j++) {

            ll mn = inf, midx;
            for(; start <= n; start++) {
                if(dp[start][j] != mx)
                    break;

                if(dp[start][j] == mx) {
                    if(j < k && start < n) {
                        if(dp[start+1][j+1] != mx - ara[start])
                            continue;
                    }
                    if(j == k && ara[start] != mx)
                        continue;
                    //cout << start << endl;
                    if(ara[start] < mn) {
                        mn = ara[start];
                        midx = start;
                    }
                }
            }
            start = midx;

            //cout << start << endl;
            if(j == pos) {
                ans = ara[start];
            }

            mx -= ara[start];
            start++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}