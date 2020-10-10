#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(ll a, ll b)

{
    return a > b;
}

int main()

{
    ll ara[1010];
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> ara[i];

    sort(ara, ara + n, cmp);

    for(ll i = 0; i < n; i++) {
        if(ara[i] < 0) {
            cout << ara[i] << endl;;
            return 0;
        }

        ll tmp = sqrt(ara[i]);
        if(tmp * tmp != ara[i]) {
            cout << ara[i] << endl;;
            return 0;
        }

    }

    return 0;
}