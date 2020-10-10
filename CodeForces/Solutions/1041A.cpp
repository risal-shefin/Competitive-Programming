#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[10009];

int main()


{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1);
    ll sum = 0;
    for(ll i = 2; i <= n; i++) {
        sum += (ara[i] - ara[i - 1] - 1);
    }

    cout << sum << endl;
    return 0;
}