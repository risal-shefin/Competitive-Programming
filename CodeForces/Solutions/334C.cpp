#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll coin[40];

int main()

{
    ll n, ans = 1;
    cin >> n;

    ll pw = 3;
    coin[0] = 1;
    for(ll i = 1; ; i++) {
        coin[i] = coin[i - 1] * pw;
        if(coin[i] > n)
            break;
    }

    for(ll i = 1; ; i++) {
        if(coin[i] > n)
            break;
        if(n % coin[i] == 0)
            continue;

        ans = (n / coin[i] + 1);
        break;
    }

    printf("%lld\n", ans);
    return 0;
}