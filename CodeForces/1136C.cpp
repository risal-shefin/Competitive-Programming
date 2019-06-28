#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[505][505], b[505][505];
multiset <ll> num1[1005], num2[1005];
int main()
{
    ll r, c;
    cin >> r >> c;
    for(ll i = 1; i <= r; i++) {
        for(ll j = 1; j <= c; j++)
            scanf("%lld", &a[i][j]);
    }
    for(ll i = 1; i <= r; i++) {
        for(ll j = 1; j <= c; j++)
            scanf("%lld", &b[i][j]);
    }
    for(ll i = 1; i <= 501; i++) {
        for(ll r = 1, c = i; r <= 501 && c >= 1; r++, c--) {
            num1[i].insert(a[r][c]);
            num2[i].insert(b[r][c]);
        }
    }
    for(ll i = 2; i <= 501; i++) {
        for(ll c = i, r = 501; c <= 501 && r >= 1; c++, r--) {
            num1[i + 501].insert(a[r][c]);
            num2[i + 501].insert(b[r][c]);
        }
    }
    for(ll i = 1; i <= 1004; i++) {
        if(num1[i] != num2[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
