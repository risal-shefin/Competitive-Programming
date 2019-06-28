#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[1000009];
int main()
 {
    ll n, ans = 0;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);
        cnt[in] = max(1LL, cnt[in - 1] + 1);
        ans = max(ans, cnt[in]);
    }
     cout << ans << endl;
     return 0;
