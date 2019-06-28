#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
int main()
{
    ll n, k, ans, am;
    cin >> n >> k;
    ll mn = inf;
    for(ll i = 1; i <= k; i++) {
        ll in;
        scanf("%I64d", &in);
        ll tmp = n % in;
        //cout << tmp << endl;
        if(mn > tmp) {
            mn = tmp;
            ans = i;
            am = n / in;
        }
    }
    cout << ans << " " << am << endl;
    return 0;
}
