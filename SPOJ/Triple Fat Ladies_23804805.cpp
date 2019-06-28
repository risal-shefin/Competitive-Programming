#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pat[] = {192, 442, 692, 942};
int main()
 {
    ll t;
    cin >> t;
    while(t--) {
        ll k;
        scanf("%lld", &k);
        ll num = (k - 1) % 4;
        ll mult = (k - 1) / 4;
        printf("%lld\n", mult * 1000 + pat[num]);
    }
     return 0;
