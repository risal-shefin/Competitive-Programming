#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[200009], ev[200009], od[200009];;

int main()

{
    ll n;
    cin >> n;;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);;;
    }

    for(ll i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            ev[i] = ara[i];
        }
        else {
            od[i] = ara[i];
        }
    }

    for(ll i = 1; i <= n; i++) {
        od[i] += od[i - 1];
        ev[i] += ev[i - 1];;
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; i++) {
        ll os = od[i - 1] + ev[n] - ev[i];
        ll es = ev[i - 1] + od[n] - od[i];

        if(os == es)
            cnt++;
    }


    cout << cnt << endl;

    return 0;
}