#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> ans;

bool check(ll n)

{
    for(ll i = 30; i >= 0; i--) {
        ll val = (1LL << i) - 1;
        if(val == n)
            return 0;
    }
    return 1;
}

int main()

{
    ll n;
    cin >> n;
    ll f = 0;
    for(ll i = 30; i >= 0; i--) {
        ll bt = (n >> i) & 1;
        if(bt == 1) {
            f = i;
            break;
        }
    }

    if(n % 2 == 0) {
        ans.push_back(0);
        n++;
    }

    while(check(n)) {

        for(ll i = f; i >= 0; i--) {
            ll bt = (n >> i) & 1;
            if(bt == 0) {
                ans.push_back(i + 1);
                n ^= ( (1LL << (i + 1)) - 1);
                n++;
                break;
            }
        }
    }

    cout << (2 * ans.size() ) << endl;
    for(ll i = 0; i < ans.size(); i++) {
        if(i != 0)
            printf(" ");
        printf("%lld", ans[i]);
    }

    if(ans.size() != 0)
        cout << endl;

    return 0;
}