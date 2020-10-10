#include <bits/stdc++.h>
using namespace std;

int main()

{
    long long n, m, k = 1, day = 0;
    cin >> n >> m;

    if(n <= m) {
        cout << n << endl;
        return 0;
    }

    n -= m;
    long long ans;
    long long lo = 0, hi = INT_MAX, mid;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        long long tmp = mid * (mid + 1) / 2;
        if(tmp >= n) {
            hi = mid - 1;
            ans = m + mid;
        }
        else
            lo = mid + 1;
    }

    cout << ans << endl;

    return 0;

}