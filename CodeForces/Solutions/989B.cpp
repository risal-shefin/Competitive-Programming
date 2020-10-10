#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    bool check = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(i + p >= s.length())
            break;

        if(s[i] == '.' && s[i + p] == '.') {
            check = 1;
            break;
        }

        if(s[i] != s[i + p]) {
            check = 1;
            break;
        }
    }

    if(!check) {
        cout << "No" << endl;
        return 0;
    }

    for(ll i = 0; i < s.length(); i++) {
        if(i + p >= s.length())
            break;

        if(s[i] == '.' && s[i + p] == '.') {
            s[i] = '0';
            s[i + p] = '1';
        }
        else if(s[i] == '.' && s[i + p] != '.') {
            ll tmp = s[i + p] - '0';
            tmp ^= 1;
            s[i] = tmp + '0';
        }
        else if(s[i] != '.' && s[i + p] == '.') {
            ll tmp = s[i] - '0';
            tmp ^= 1;
            s[i + p] = tmp + '0';
        }
    }

    for(ll i = 0; i < s.length(); i++) {

        if(s[i] == '.')
            s[i] = '0';
    }

    cout << s << endl;

    return 0;
}