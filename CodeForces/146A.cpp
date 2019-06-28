#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    ll n;
    cin >> n >> s;
    ll f = 0, l = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] != '4' && s[i] != '7') {
            cout << "NO" << endl;
            return 0;
        }
        if(i < n / 2)
            f += (s[i] - '0');
        else
            l += (s[i] - '0');
    }
    if(f == l)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
