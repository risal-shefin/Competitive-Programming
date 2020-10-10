#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a, ll n)

{
    ll ans = 1;
    for(ll i = 1; i <= n; i++) {
        ans *= a;
        //cout << a << endl;
    }

    return ans;
}

int main()

{
    ll n, k;
    cin >> n >> k;
    if(k == 1)
        cout << n << endl;
    else {
        ll cnt = 0;
        ll tmp = n;
        while(tmp != 0) {
            tmp /= 2;
            cnt++;
        }

        cout << power(2, cnt) - 1 << endl;
    }

    return 0;
}