#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
int main()
{
    map <string, string> mp;
    map <string, string> :: iterator it;
    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";;
    ll n;
    cin >> n;
    string ara[n + 5];
    map <string, bool> mark;
    for(ll i = 0; i < n; i++) {
        cin >> ara[i];
        mark[ ara[i] ] = 1;
    }
    ll cnt = 0, indx = 0;
    string ans[8];
    for(it = mp.begin(); it != mp.end(); it++) {
        if(mark[it -> first] == 0) {
            ans[indx++] = it -> second;
            cnt++;
        }
    }
    cout << cnt << endl;
    for(ll i = 0; i < cnt; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
