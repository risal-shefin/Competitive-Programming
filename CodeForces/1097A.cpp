#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s, s1;
    cin >> s;
    bool chk = 0;
    for(ll i = 1; i <= 5; i++) {
        cin >> s1;
        if(s[0] == s1[0] || s[1] == s1[1])
            chk = 1;
    }
    if(chk)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
