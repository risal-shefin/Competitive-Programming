#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18;

ll dp[22][100009], ara[100009], cnt[100009], cost = 0;
ll curStart = 0, curStop = -1;

void add(ll val) {
    cost -= (cnt[val] * (cnt[val] - 1)) / 2;
    cnt[val]++;
    cost += (cnt[val] * (cnt[val] - 1)) / 2;
}

void del(ll val) {
    cost -= (cnt[val] * (cnt[val] - 1)) / 2;
    cnt[val]--;
    cost += (cnt[val] * (cnt[val] - 1)) / 2;
}

void calculateCost(ll start, ll stop)

{
    while(curStart > start)
        add(ara[--curStart]);
    while(curStop < stop)
        add(ara[++curStop]);

    while(curStart < start)
        del(ara[curStart++]);
    while(curStop > stop)
        del(ara[curStop--]);

    //cout << curStart << " " << curStop << " " << cost << endl;
}

void solve(ll lo, ll hi, ll left, ll right, ll k)

{
    if(lo > hi)
        return;

    ll mid = (lo + hi) / 2, idx = 0;
    dp[k][mid] = inf;
    for(ll i = min(mid - 1, right); i >= left; i--) {
        ll now = i + 1;
        calculateCost(now, mid);

        //cout << " " << now << "  " << mid << "  " << cost << endl;
        if(dp[k-1][i] + cost < dp[k][mid]) {
            dp[k][mid] = dp[k-1][i] + cost;
            idx = i;
        }
    }

    //cout << idx << " " << k << " " << mid << " " << cost << " " << right << endl;
    solve(lo, mid - 1, left, idx, k);
    solve(mid + 1, hi, idx, right, k);
}

int main()

{
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= 20; j++)
            dp[j][i] = inf;

    dp[0][0] = 0;
    for(ll i = 1; i <= k; i++) {
        solve(1, n, 0, n, i);
        //cout << dp[1][5] << endl;
    }

    cout << dp[k][n] << endl;

    return 0;
}