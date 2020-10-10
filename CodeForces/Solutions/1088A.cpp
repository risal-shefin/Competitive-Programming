#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll x;
    cin >> x;
    for(ll i = 1; i <= x; i++) {
        for(ll j = 1; j <= x; j++) {
            if(i % j == 0) {
                if(i * j > x && i < x * j) {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}