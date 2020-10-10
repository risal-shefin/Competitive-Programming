#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

int main()

{
    ll a, b;
    cin >> a >> b;
    if(a > b)
        swap(a, b);

    ll mid = (a + b) / 2;
    ll n1 = (mid - a), n2 = b - mid;
    ll ans = (n1 * (n1 + 1)) / 2 + (n2 * (n2 + 1)) / 2;

    cout << ans << endl;

    return 0;
}