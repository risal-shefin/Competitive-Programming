#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[1008];

int main()

{
    ll n;
    cin >> n;
    vector <ll> ans;

    ara[0] = 0;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);


        if(ara[i] - ara[i - 1] != 1)
            ans.push_back(ara[i - 1]);

        if(i == n) {
            ans.push_back(ara[i]);
            continue;
        }
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++) {

        if(i != 0)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;
    return 0;
}