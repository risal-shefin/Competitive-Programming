#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> ans;
int main()
{
    ll n, k, s;
    cin >> n >> k >> s;
    ll mx = n - 1;
    if(s > (n - 1) * k || (s < k) ) {
        printf("NO\n");
        return 0;
    }
    ll prv = 1, pls = 0;
    ll per = s / k;
    if(s % k != 0) {
        pls = 1;
    }
    ll sum = 0;
    for(ll i = 1; i <= k; i++) {
        if(i % 2 == 1)
            ans.push_back(prv + per + pls);
        else
            ans.push_back(prv - per - pls);
        sum = sum + per + pls;
        ll baki = k - i;
        ll dif = s - sum;
        if(dif == 0)
            break;
        if(dif % baki == 0)
            pls = 0;
        prv = ans[i - 1];
    }
    printf("YES\n");
    for(ll i = 0; i < ans.size(); i++)
        printf("%lld ", ans[i]);
    cout << endl;
    return 0;
}
