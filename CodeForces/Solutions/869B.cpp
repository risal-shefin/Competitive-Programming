#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 1 << endl;
        return 0;
    }

    ll mul = 1;
    for(ll i = a + 1, j = 1; i <= b && j <= 20; i++, j++) {
        ll num = i % 10;
        mul *= num;
        mul %= 10;
    }

    cout << mul << endl;

    return 0;
}