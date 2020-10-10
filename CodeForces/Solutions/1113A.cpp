#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, v;
    cin >> n >> v;
    ll need = n - 1, cst = 0, ekhon = 0;
    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            ekhon--;

        ll am = min(need, v - ekhon);
        //cout << am << "  " << v << " " << ekhon << endl;
        cst += (am * i);
        need -= am;
        ekhon += am;
    }

    cout << cst << endl;

    return 0;
}