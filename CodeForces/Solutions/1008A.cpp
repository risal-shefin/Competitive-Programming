#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    string s;
    cin >> s;

    if(s.length() == 1) {
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'|| s[0] == 'n') {
            printf("YES\n");
            return 0;
        }
        else {
            printf("NO\n");
            return 0;
        }
    }

    bool flag = 1;
    for(ll i = 0; i < s.length(); i++) {

        if(i == s.length() - 1) {
            if( !(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'n') ) {
                flag = 0;
                continue;
            }
        }

        else {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'n') {
                continue;
            }
            else {
                if( !(s[i + 1] == 'a' || s[i + 1] == 'e' || s[i+ 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u') ) {
                      flag = 0;
                }
            }
        }
    }

    if(flag) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}