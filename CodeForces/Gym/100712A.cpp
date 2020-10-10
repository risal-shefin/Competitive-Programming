#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        ll n, slv, tme, mx = -1, mn = 1e18;
        string s, ans;
        cin >> n;
        for(ll i = 1; i <= n; i++) {
            cin >> s >> slv >> tme;
            if(slv > mx) {
                mx = slv;
                mn = tme;
                ans = s;
            }
            else if(slv == mx && tme < mn) {
                mn = tme;
                ans = s;
            }
        }

        cout << ans << endl;
    }
    return 0;
}