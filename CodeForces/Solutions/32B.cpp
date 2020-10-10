#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    std::ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    ll start = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            if(start == i) {
                cout << 0;
                start = i + 1;
                continue;
            }
            else {
                cout << 1;
                start = i + 1;
                continue;
            }
        }
        else {
            if(start == i)
                continue;

            cout << 2;
            start = i + 1;
            continue;
        }
    }

    cout << endl;

    return 0;
}