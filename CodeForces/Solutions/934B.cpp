#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{
    ll k;
    cin >> k;
    if(k > 36) {
        cout << "-1" << endl;
        return 0;
    }
    if(k == 0) {
        cout << "1" << endl;
        return 0;
    }

    if(k == 1) {
        cout << "4" << endl;
        return 0;
    }


    while(k != 0) {
        k -= 2;
        cout << "8";
        if(k == 1) {
            cout << "4";
            break;
        }
    }

    cout << endl;

    return 0;
}