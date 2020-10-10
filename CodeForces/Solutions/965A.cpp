#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll k, n, s, p;
    cin >> k >> n >> s >> p;
    ll bana = n / s;
    if(n % s != 0)
        bana++;
    ll tot = bana * k;
    ll pck = tot / p;
    if(tot % p != 0)
        pck++;

    cout << pck << endl;

    return 0;
}