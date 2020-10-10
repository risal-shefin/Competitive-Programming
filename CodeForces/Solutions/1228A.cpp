#include <bits/stdc++.h>
using namespace std;

#define ll long long

bitset <10> chk;

int main()

{
    ll l, r;
    cin >> l >> r;
    for(ll i = l; i <= r; i++) {
        ll n = i;
        chk.reset();
        bool ch = 0;
        while(n) {
            ll rem = n % 10;
            if(chk[rem]) {
                ch = 1;
                break;
            }

            n /= 10;
            chk[rem] = 1;
        }

        if(!ch) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}