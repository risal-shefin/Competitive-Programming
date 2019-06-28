#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100009], pos[100009], sum = 0;
int main()
{
    ll n, l;
    cin >> n >> l;
    for(ll i = 1; i < n; i++)
        scanf("%lld", &ara[i]);
    pos[0] = 1e18;
    for(ll i = 0; i < n; i++) {
        ll cnt = pos[i];
        for(ll j = i + l; j > i; j--) {
            if(cnt <= 0)
                break;
            if(j >= n) {
                sum += cnt;
                cnt = 0;
                break;
            }
            if(ara[j] >= cnt) {
                ara[j] -= cnt;
                pos[j] += cnt;
                cnt = 0;
            }
            else {
                pos[j] += ara[j];
                cnt -= ara[j];
                ara[j] = 0;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
