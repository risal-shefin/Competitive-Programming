#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin >> s;
    ll len = s.length();
    ll mid = len / 2;
    if(len % 2 == 0)
        mid--;
    string ans = "";
    ll left = mid, right = mid + 1;
    bool state = 1;
    for(ll i = 1; i <= len; i++) {
        if(!state) {
            ans += s[right];
            right++;
        }
        else {
            ans += s[left];
            left--;
        }
        state ^= 1;
    }
    cout << ans << endl;
    return 0;
}
