#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll mark = 0, len = 1e9, id = n;
    for(ll i = 1; i <= n; i++) {
        ll tmp = n / i;
        if(n % i != 0)
            tmp++;
        if(tmp + i < len) {
            len = tmp + i;
            mark = i;
        }
    }
    while(1) {
        if(id < 0)
            break;
        ll start = max(1LL, id - mark + 1);
        for(ll i = start; i <= id; i++)
            printf("%lld ", i);
        id -= mark;
    }
    cout << endl;
    return 0;
}
