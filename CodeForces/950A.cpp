#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL << 62)
int main()
{
    ll l, r, a;
    cin >> l >> r >> a;
    if(l > r)
        swap(l, r);
    ll ans = l;
    ll dif = r - l;
    if(dif > a) {
        ans += a;
    }
    else {
        ans += dif;
        ll tmp = a - dif;
        tmp = tmp / 2;
        ans += tmp;
    }
    cout << 2 * ans << endl;
    return 0;
}
