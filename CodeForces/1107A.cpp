#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
        std::ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    string s;
    while(q--) {
        ll k;
        cin >> k;
        cin >> s;
        if(k == 2) {
            if(s[0] >= s[1]) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << s[0] << " " << s[1] << endl;
            }
        }
        else {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " ";
            for(ll i = 1; i < s.length(); i++)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}
