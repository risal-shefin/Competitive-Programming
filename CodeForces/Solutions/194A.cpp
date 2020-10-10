#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, k;
    cin >> n >> k;
    int tmp = k / n;
    if(tmp == 2) {
        int ans = n - k % n;
        cout << ans << endl;
    }
    else
        cout << 0 << endl;

    return 0;
}