#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll ara[20];
    ll n;
    cin >> n;

    bool check = 0;
    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        sum += ara[i];
    }
    if(n == 1) {
        cout << "-1" << endl;
        return 0;
    }
    ll per = sum / 2;

    vector <ll> ans;
    ll sumt = 0;
    for(ll i = 1; i <= n; i++) {
        sumt += ara[i];
        ans.push_back(i);
        if(sumt != (sum - sumt) && sumt != 0 && (sum - sumt) != 0) {
            check = 1;
            break;
        }
    }

    if(!check) {
        cout << "-1" << endl;
    }

    else {
        cout << ans.size() << endl;
        for(ll i = 0; i < ans.size(); i++) {
            if(i != 0)
                printf(" ");
            cout << ans[i];
        }
    }

    cout << endl;

    return 0;
}