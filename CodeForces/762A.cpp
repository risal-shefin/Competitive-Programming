#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k;
    cin >> n >> k;
    vector <ll> div;
    ll sqt = sqrt(n);
    for(ll i = 1; i <= sqt; i++) {
        if(n % i == 0) {
            div.push_back(i);
            ll tmp = n / i;
            if(tmp != i)
                div.push_back(tmp);
        }
    }
    sort(div.begin(), div.end());
    if(div.size() < k)
        cout << -1 << endl;
    else
        cout << div[k - 1] << endl;
    return 0;
}
