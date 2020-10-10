#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll indx[300009], ara[300009], n, k;

bool isPossible(ll dif)

{
    ll last = 0;
    for(ll i = k; i <= n; i++) {
        ll j = indx[ i - k ];
        if(ara[i] - ara[j + 1] <= dif)
            last = i;

        indx[i] = last;
    }

    return indx[n] == n;
}

int main()

{
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1);

    ll lo = 0, hi = 2e9, ans;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if( isPossible(mid) ) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}