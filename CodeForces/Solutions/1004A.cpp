#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[105];

int main()

{
    ll n, d;
    cin >> n >> d;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    map <ll, bool> mark;
    ll cnt = 2;

    for(ll i = 1; i < n; i++) {
        ll p1 = ara[i] + d;
        ll p2 = ara[i + 1] - d;

        if(p2 == p1) {
            cnt++;
        }
        else if(p2 > p1) {
            cnt += 2;
        }
    }

    cout << cnt << endl;

    return 0;
}