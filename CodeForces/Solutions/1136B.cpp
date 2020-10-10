#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, k;
    cin >> n >> k;
    ll lo = 1, hi = n;

    ll ld = k - lo, rd = hi - k, sum;
    if(ld <= rd) {
        sum = 2 * (ld + 1);

        sum += (2 * ld);

        sum += rd;
        sum += (2 * rd);
        sum ++;
    }
    else {
        sum = 2 * (rd + 1);

        sum += (2 * rd);

        sum += ld;
        sum += (2 * ld);
        sum ++;
    }

    cout << sum << endl;

    return 0;
}