#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll row, col, in;
    for(ll i = 1; i <= 5; i++) {
        for(ll j = 1; j <= 5; j++) {
            scanf("%lld", &in);
            if(in == 1) {
                row = i;
                col = j;
            }
        }
    }

    ll mov = abs(row - 3);
    mov += abs(col - 3);

    cout << mov << endl;
    return 0;
}