#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll a;
    cin >> a;

    for(ll i = a + 1; i <= a + 1000; i++) {
        bool check = 0;
        ll num = abs(i);
        while(num) {
            ll rem = num % 10;
            if(rem == 8) {
                check = 1;
                break;
            }
            num /= 10;
        }
        if(check) {
            cout << (i - a) << endl;
            return 0;
        }
    }

    return 0;
}