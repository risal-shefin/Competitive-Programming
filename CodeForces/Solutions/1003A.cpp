#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, ara[105] = {}, ans = 0;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);
        ara[in]++;
        ans = max(ans, ara[in]);
    }

    cout << ans << endl;
    return 0;
}