#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n;
    string s;
    cin >> n >> s;

    vector <ll> div;
    ll sqt = sqrt(n);
    for(ll i = 1; i <= sqt; i++) {

        if(n % i == 0) {

            div.push_back(i);
            ll y = n / i;
            if(y != i)
                div.push_back(y);
        }
    }

    sort(div.begin(), div.end());

    for(ll i = 0; i < div.size(); i++) {
        reverse(s.begin(), s.begin() + div[i]);
    }

    cout << s << endl;

    return 0;
}