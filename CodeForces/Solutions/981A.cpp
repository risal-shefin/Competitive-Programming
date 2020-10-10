#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18

int main()

{
    string s;
    cin >> s;
    ll ans = 0;
    for(ll i = 0; i < s.length(); i++) {
        string s2 = "";
        for(ll j = i; j < s.length(); j++) {
            s2 += s[j];
        }

        string tmp = s2;
        reverse(s2.begin(), s2.end());

        ll len = s2.length();
        if(tmp != s2) {
            ans = max(ans, len);
        }
    }

    cout << ans << endl;
    return 0;
}