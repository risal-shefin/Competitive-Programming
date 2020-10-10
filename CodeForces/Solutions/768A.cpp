#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n;
    cin >> n;
    ll ara[n + 5];
    for(ll i = 0; i < n; i++)
        scanf("%lld", &ara[i]);
    sort(ara, ara + n);

    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        ll indx = lower_bound(ara, ara + n, ara[i]) - ara;
        ll indx2 = upper_bound(ara, ara + n, ara[i]) - ara;

        if(indx == 0)
            continue;
        if(indx2 == n)
            continue;

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}