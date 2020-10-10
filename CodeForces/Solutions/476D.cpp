#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, k, mx = 0;
    cin >> n >> k;

    cout << k * (6 * (n - 1) + 5) << endl;
    for(ll i = 1; i <= n; i++) {

        for(ll j = 1; j <= 4; j++) {
            if(j != 1)
                printf(" ");
            if(j != 4)
                printf("%lld", k * (6 * (i - 1) + j) );
            else
                printf("%lld", k * (6 * (i - 1) + 5) );

        }
        printf("\n");

    }

    return 0;
}