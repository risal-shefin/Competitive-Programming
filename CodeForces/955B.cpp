#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL << 62)
map <char, ll> mark;
map <char, ll> :: iterator it;
ll cnt = 0;
int main()
{
    string s;
    cin >> s;
    if(s.length() < 4) {
        cout << "No" << endl;
        return 0;
    }
    for(ll i = 0; i < s.length(); i++) {
        if(mark[ s[i] ] == 0) {
            cnt++;
        }
        mark[ s[i] ]++;
    }
    if(cnt > 4 || cnt == 1) {
        cout << "No" << endl;
        return 0;
    }
    if(cnt == 2) {
        bool check = 1;
        for(it = mark.begin(); it != mark.end(); it++) {
            ll ase = it -> second;
            if(ase < 2) {
                check = 0;
            }
        }
        if(check == 0) {
            cout << "No" << endl;
            return 0;
        }
        else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
