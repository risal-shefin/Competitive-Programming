#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1 << 62

int main()

{
    ll n, cnt = 0;
    cin >> n;
    for(ll i = 2; i <= n; i++) {
        if(n % i == 0) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}