#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[1009];

int main()

{
    ll n;
    cin >> n;
    set <ll> s;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        s.insert(ara[i]);
    }

    for(auto it = s.begin(); it != s.end(); it++) {
        ll num = *it;
        if(num % 2) {
            for(ll i = 1; i <= n; i++) {
                if(ara[i] == num) {
                    ara[i]++;
                    s.insert( ara[i] );
                }
            }
        }
        else {
            for(ll i = 1; i <= n; i++) {
                if(ara[i] == num)
                    ara[i]--;
            }
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