#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
void imp()
{
    cout << "Impossible" << endl;
    exit(0);
}
bool isPal(ll start)
{
    ll half = (start + (s.length() / 2) ) % s.length();
    ll stop = start - 1;
    stop = (stop + s.length()) % s.length();
    for(ll i = start, j = stop; ; i++, j--) {
        i = i % s.length();
        j = (j + s.length() ) % s.length();
        if(i == half)
            break;
        if(s[i] != s[j])
            return false;
    }
    return true;
}
bool isSame(ll start)
{
    for(ll i = 0, j = start; i < s.length(); i++, j++) {
        j %= s.length();
        if(s[i] != s[j])
            return false;
    }
    return true;
}
bool isPos()
{
    for(ll i = 0; i < s.length(); i++) {
        if(isPal(i)) {
            if(!isSame(i))
                return true;
        }
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> s;
    /// impossible
    if(s.length() <= 2) {
        imp();
    }
    bool chk = 1;
    for(ll i = 1; i < s.length(); i++) {
        if(s[i] != s[0]) {
            chk = 0;
            break;
        }
    }
    if(chk)
        imp();
    chk = 1;
    ll mid = s.length() / 2;
    for(ll i = 0, j = s.length() - 1; i < mid; i++, j--) {
        if(s[i] != s[0] || s[j] != s[0]) {
            chk = 0;
            break;
        }
    }
    if(chk)
        imp();
    if(isPos() && s.length() % 2 == 0) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}
