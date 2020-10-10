#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[300009];

int main()

{
    ll n, x, y;
    cin >> n >> x >> y;

    for(ll i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);

        ara[i] = ch - '0';
    }

    ll lst = 1, cst = 0, zero = 0;
    bool check = 1;
    for(ll i = 1; i <= n; i++) {
        bool state = 0;
        //cout << ara[i] << endl;
        if(ara[i] == 1 && check == 0) {
            if(x < y) {
                cst += x;
                state = 1;
            }
            else {
                cst += y;
                check = 1;
            }
        }

        if(ara[i] == 0)
            check = 0;

        if(ara[i] == 1) {
            for(; i <= n; i++) {
                if(ara[i] == 0) {
                    i--;
                    break;
                }
            }
            if(i > n && state) {
                cst = cst - x + y;
                check = 1;
            }
        }

    }

    if(!check)
        cst += y;

    cout << cst << endl;

    return 0;
}