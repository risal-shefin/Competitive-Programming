#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2e18
int main()
{
    string s;
    cin >> s;
    ll prl = 0, lnk = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == 'o')
            prl++;
        else
            lnk++;
    }
    if(prl <= 1) {
        cout << "YES" << endl;
        return 0;
    }
    if(lnk == 0) {
        cout << "YES" << endl;
        return 0;
    }
    if(lnk % prl == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
