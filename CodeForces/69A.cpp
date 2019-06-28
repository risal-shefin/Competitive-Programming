#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x = 0, y = 0, z = 0, n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >>  b >> c;
        x += a;
        y += b;
        z += c;
    }
    if(x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
