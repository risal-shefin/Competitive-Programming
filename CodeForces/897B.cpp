#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll k, p;
    cin >> k >> p;
    ll sum = 0;
    for(int i = 1; i <= k; i++) {
        ll tmp = i, n = i;
        while(tmp != 0) {
            ll dig = tmp % 10;
            n = n * 10 + dig;
            tmp /= 10;
        }
        sum = (sum % p + n % p) % p;
    }
    cout << sum << endl;
    return 0;
}
