#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100009];

int main()

{
    multiset <ll> mul;
    multiset <ll> :: iterator it;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        mul.insert( ara[i] );
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; i++) {
        it = mul.upper_bound( ara[i] );

        if(it != mul.end()) {
            //cout << ara[i] << "  " << *it << endl;
            cnt++;
            mul.erase(it);
        }
    }

    cout << cnt << endl;

    return 0;
}