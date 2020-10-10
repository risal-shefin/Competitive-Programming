#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define ll long long

int main()

{
    string s;
    cin >> s;
    ll cnt[5] = {};

    char ch = 'a';
    if(s[0] != 'a') {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < s.length(); i++) {
        if(s[i] > ch + 1) {
            cout << "NO" << endl;
            return 0;
        }
        if(s[i] == ch + 1)
            ch++;

        if(s[i] != ch) {
            cout << "NO" << endl;
            return 0;
        }

        cnt[ s[i] - 'a']++;
    }

    if(ch != 'c') {
        cout << "NO" << endl;
        return 0;
    }

    if(cnt[0] == cnt[2] || cnt[1] == cnt[2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}