#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[10009];
int main()
{
    ll start = 10;
    for(int i = 1; i <= 10000; i++) {
        while(1) {
            start += 9;
            ll sum = 0, n = start;
            while(n != 0) {
                ll tmp = n % 10;
                sum += tmp;
                n /= 10;
            }
            if(sum == 10)
                break;
        }
        ans[i] = start;
    }
    int k;
    cin >> k;
    cout << ans[k] << endl;
    return 0;
}
