#include <bits/stdc++.h>
using namespace std;

#define ll long long
set <char> cnt[105];

int main()

{
    string s;
    cin >> s;
    if(s.length() < 3) {
        cout << "No" << endl;
        return 0;
    }
    bool check = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == '.')
            continue;

        cnt[i].insert(s[i]);
        if(i == 0) {
            cnt[i].insert(s[i]);
            cnt[i + 1].insert(s[i]);
        }
        else if(i == s.length() - 1) {
            cnt[i].insert(s[i]);
            cnt[i - 1].insert(s[i]);
        }
        else {
            cnt[i].insert(s[i]);
            cnt[i + 1].insert(s[i]);
            cnt[i - 1].insert(s[i]);
        }
    }

    for(ll i = 0; i < s.length(); i++) {
        if(cnt[i].size() == 3) {
            check = 1;
            break;
        }
    }

    if(check)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}