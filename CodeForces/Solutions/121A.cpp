#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> lucky;

void gen(ll num)

{
    if(num > 44444444444)
        return;

    if(num > 0)
        lucky.push_back(num);

    gen(num * 10 + 4);
    gen(num * 10 + 7);
}

int main()

{

    gen(0);
    sort(lucky.begin(), lucky.end());

    ll l, r;
    cin >> l >> r;

    ll prv = l, ans = 0;
    for(ll i = 0; i < lucky.size(); i++) {
        if(lucky[i] < prv)
            continue;

        if(lucky[i] >= r) {
            ans += (r - prv + 1) * lucky[i];
            break;
        }

        ans += (lucky[i] - prv + 1) * lucky[i];
        prv = lucky[i] + 1;
    }

    cout << ans << endl;

    return 0;
}