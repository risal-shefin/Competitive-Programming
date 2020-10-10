#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll ylw, bl;
    cin >> ylw >> bl;
    ll y, g, b;
    cin >> y >> g >> b;
    ll ylw2 = y * 2 + g;
    ll bl2 = g + 3 * b;

    ll ans1 = ylw2 - ylw;
    ll ans2 = bl2 - bl;

    ans1 = max((ll)0, ans1);
    ans2 = max((ll)0, ans2);
    cout << ans1 + ans2 << endl;

    return 0;
}