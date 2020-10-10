#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ios::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length() != s2.length()) {
        cout << "NO" << endl;
        return 0;
    }

    if(s1.length() == 1) {
        if(s1 != s2) {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;

        return 0;
    }

    bool state1 = 0, state2 = 0;
    for(ll i = 0; i < s1.length(); i++) {
        if(s1[i] == '1')
            state1 = 1;
        if(s2[i] == '1')
            state2 = 1;
    }

    if(state1 == state2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}