#include <bits/stdc++.h>

using namespace std;

int main()

{
    char ch = 'a';
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'z')
            continue;
        if(s[i] == ch) {
            ch++;
        }
        else if(s[i] == (ch - 1)) {
            s[i] = ch;
            ch++;
        }
    }

    if(ch >= 'z')
        cout << s << endl;
    else
        cout << -1 << endl;

    return 0;
}