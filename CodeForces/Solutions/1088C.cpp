#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[2009];

int main()

{
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    ll mx;
    cout << n + 1 << endl;
    cout << 2 << " " << n << " " << 1 << endl;
    cout << 1 << " " << n << " " << 1000000 << endl;

    ll mod = 1000000 - 1;
    for(ll i = 1; i <= n - 1; i++) {
        printf("2 %lld %lld\n", i, mod);
        mod--;
    }

    return 0;
}