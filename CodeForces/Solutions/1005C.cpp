#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[200009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i]);
    }

    ll mv = 0;
    sort(ara, ara + n);
    for(ll i = 0; i < n; i++) {

        ll x = ara[i];
        ll pw = 2;
        bool check = 0;
        for(ll j = 1; j <= 40; j++) {
            if(pw <= x) {
                pw *= 2;
                continue;
            }

            ll dif = pw - x;
            //cout << x << "  " << dif << endl;
            ll pos = lower_bound(ara, ara + n, dif) - ara;
            if(ara[pos] == dif) {
                if(ara[pos] == x) {
                    if(ara[pos + 1] == x)
                        check = 1;
                }
                else
                    check = 1;
            }
            pw *= 2;
        }

        if(!check)
            mv++;
    }

    cout << mv << endl;

    return 0;
}