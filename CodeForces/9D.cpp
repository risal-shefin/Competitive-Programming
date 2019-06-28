#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pll pair <ll, ll>
ll n, h;
pll dp[37][37][37][37];
bool check[37][37][37][37];
pll dfs(ll start, ll root, ll stop, ll lv)
{
    if(start == stop) {
        if(lv >= h) return pll(1, 0);
        else return pll(0, 1);
    }
    if(check[start][root][stop][lv]) return dp[start][root][stop][lv];
    vector <pll> lft, rgt;
    ll ret = 0, ret2 = 0;
    for(ll i = start; i < root; i++) {
        pll p = dfs(start, i, root - 1, lv + 1);
        lft.push_back(p);
        if(root == stop) {
            ret += p.first;
            ret2 += p.second;
        }
    }
    for(ll i = root + 1; i <= stop; i++) {
        pll p = dfs(root + 1, i, stop, lv + 1);
        for(ll j = 0; j < lft.size(); j++) {
            ret += (p.first * lft[j].first);
            ret += (p.first * lft[j].second);
            ret += (p.second * lft[j].first);
            ret2 += (p.second * lft[j].second);
        }
        if(root == start) {
            ret += p.first;
            ret2 += p.second;
        }
    }
    check[start][root][stop][lv] = 1;
    dp[start][root][stop][lv] = pll(ret, ret2);
    return dp[start][root][stop][lv];
}
int main()
{
    cin >> n >> h;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        pll p = dfs(1, i, n, 1);
        ans += p.first;
    }
    cout << ans << endl;
    return 0;
}
