#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL << 60)
int main()
{
    ll x, y, z;
    cin >> x >> y >> z;
    if(x % z == 0 || y % z == 0) {
        ll tot = x / z + y / z;
        cout << tot << " " << 0 << endl;
    }
    else {
        ll rem1 = x % z, rem2 = y % z;
        ll need1 = z - rem1, need2 = z - rem2;
        ll transfer = inf, tot = x / z + y / z;
        if(need1 <= rem2) {
            transfer = min(transfer, need1);
            tot = x / z + y / z + 1;
        }
        if(need2 <= rem1) {
            transfer = min(transfer, need2);
            tot = x / z + y / z + 1;
        }
        cout << tot << " " << (transfer==inf? 0:transfer) << endl;
    }
    return 0;
}
