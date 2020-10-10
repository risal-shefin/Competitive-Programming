#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    string s;
    cin >> s;

    ll ans = 0;
    for(ll i = 0; i < s.length(); i++) {
        ans += 25;
    }
    ans += 26;

    cout << ans << endl;

    return 0;
}