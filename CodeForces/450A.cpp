#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2e18
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ara[n + 5], ans, last;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);
    while(1) {
        bool test = 1;
        for(ll i = 1; i <= n; i++) {
            if(ara[i] != 0) {
                test = 0;
                last = i;
            }
            if(m >= ara[i]) {
                ara[i] = 0;
            }
            else {
                ara[i] -= m;
            }
        }
    if(test)
        break;
    }
    cout << last << endl;
    return 0;
}
