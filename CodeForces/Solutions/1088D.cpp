#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll big, a = 0, b = 0, q1, q2;
    cout << "? 0 0" << endl;
    cin >> big;
    for(ll i = 29; i >= 0; i--) {
        cout << "? " << (a ^ (1 << i)) << " " << b << endl;
        cin >> q1;
        cout << "? " << a << " " << (b ^ (1 << i)) << endl;
        cin >> q2;

        if(q1 == q2) {
            if(big == 1)
                a |= (1 << i);
            else if(big == -1)
                b |= (1 << i);

            big = q1;
        }
        else if(q1 == -1) {
            a |= (1 << i);
            b |= (1 << i);
        }
    }

    cout << "! " << a << " " << b << endl;

    return 0;
}