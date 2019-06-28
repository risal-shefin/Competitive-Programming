#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    std::ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    ll si = -1, ti = -1;
    for(ll i = s.length() - 1, j = t.length() - 1; i >= 0 && j >= 0; i--, j--) {
        if(s[i] != t[j]) {
            break;
        }
        si = i;
        ti = j;
    }
    if(si == -1) {
        cout << s.length() + t.length() << endl;
        return 0;
    }
    ll mv = si + ti;
    cout << mv << endl;
    return 0;
}
