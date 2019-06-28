#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
ll n, k, ara[5009];
ll xorcs[5009][5009], xorsum[5009][5009], dp[5009][5009];
void solve(ll lo, ll hi, ll left, ll right, ll part)
 {
    if(lo > hi) return;
    ll mid = (lo + hi) / 2;
     dp[mid][part] = inf;
    ll indx;
    for(ll i = left; i <= right && i <= mid; i++) {
         ll c = dp[i - 1][part - 1] + xorsum[i][mid];
        if(c < dp[mid][part]) {
            dp[mid][part] = c;
            indx = i;
        }
    }
     solve(lo, mid - 1, left, indx, part);
    solve(mid + 1, hi, indx, right, part);
}
int main()
 {
    scanf("%lld %lld", &n, &k);
    k++;
    for(ll i = 1; i <= n; i++) scanf("%lld", &ara[i]);
     for(ll i = 1; i <= n; i++) {
        for(ll j = i + 1; j <= n; j++)
            xorcs[i][j] = (ara[i] ^ ara[j]) + xorcs[i][j - 1];
    }
     for(ll i = 1; i <= n; i++) {
        ll sum = 0;
        for(ll j = i - 1; j >= 1; j--) {
            sum += xorcs[j][i];
            xorsum[j][i] = sum;
        }
    }
     for(ll i = 0; i <= 5002; i++) {
            dp[i][0] = inf;
    }
    dp[0][0] = 0;
     for(ll i = 1; i <= k; i++)
        solve(1, n, 1, n, i);
     cout << dp[n][k] << endl;
     return 0;
