#include <bits/stdc++.h>
using namespace std;

#define ll int

ll dp[6105][6105];
string s;

ll solve(ll l, ll r)

{
    if(l >= r) return 0;
    ll &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = 1e8;
    if(s[l] != s[r]) ret = min(1 + solve(l, r - 1), 1 + solve(l + 1, r));
    else ret = solve(l + 1, r - 1);

    return ret;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        cout << solve(0, s.length() - 1) << endl;
    }

    return 0;
