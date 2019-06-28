#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[200009];
bool mark[200009];
int main()
{
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i]);
    }
    sort(ara, ara + n);
    for(ll i = 0; i < n; i++) {
        ll lo = 0, hi = n - 1, pos = 0;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(ara[mid] <= ara[i])
                lo = mid + 1;
            else if(ara[mid] <= ara[i] + k) {
                pos = 1;
                //cout << ara[i] << "  " << ara[mid] << endl;
                break;
            }
            else
                hi = mid - 1;
        }
        if(pos)
            mark[i] = 1;
    }
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(!mark[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
