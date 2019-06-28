#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k;
    cin >> n >> k;
    ll left, md;
    for(ll i = k - 1; i >= 1; i--) {
        if(n % i == 0) {
            left = n / i;
            md = i;
            break;
        }
    }
    ll x = k * left + md;
    cout << x << endl;
    return 0;
}
