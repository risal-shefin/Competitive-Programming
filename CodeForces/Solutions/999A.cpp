#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, k;
    cin >> n >> k;
    vector <ll> v;
    for(ll i = 1; i <= n; i++) {
        ll num;
        scanf("%lld", &num);
        v.push_back(num);
    }

    while(v.size() > 0) {
        ll x = v[0];
        if(x > k) {
            ll y = v[ v.size() - 1];

            if(y > k)
                break;

            v.erase( v.end() - 1);
        }
        else {
            v.erase(v.begin());
        }

    }

    cout << n - v.size() << endl;

    return 0;
}