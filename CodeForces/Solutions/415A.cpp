#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[105];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++) {
        ll inp;
        scanf("%lld", &inp);
        for(ll j = inp; j <= n; j++) {
            if(ara[j] != 0)
                break;
            ara[j] = inp;
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", ara[i]);
    }

    cout << endl;

    return 0;
}