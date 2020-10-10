#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{
    int n;
    string s;
    cin >> n >> s;
    bool mark = 0;
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'y')
        mark = 1;
    cout << s[0];

    for(int i = 1; i < n; i++) {
        if(mark == 1 && ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ) ) {
            continue;
        }

        cout << s[i];

        if(mark == 0 && ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ) ) {
            mark = 1;
            continue;
        }

        mark = 0;

    }
    
    cout << endl;
    return 0;
}