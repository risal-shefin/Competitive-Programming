#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mark[55];
vector <ll> ans;

int main()

{
    ll n, v;
    cin >> n >> v;
    for(ll i = 1; i <= n; i++) {
        ll m;
        scanf("%lld", &m);
        for(ll j = 1; j <= m; j++) {
            ll inp;
            scanf("%lld", &inp);
            if(v > inp && mark[i] != 1) {
                ans.push_back(i);
                mark[i]  = 1;
            }
        }
    }

    cout << ans.size() << endl;
    for(ll i: ans)
        cout << i << " ";


    return 0;
}