#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 62
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0, y = 0, cnt = 0;
    bool flag1 = 0, flag2 = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == 'R')
            x++;
        if(s[i] == 'U')
            y++;
        if(y > x) {
            flag2 = 1;
            if(i != 0) {
                if(flag1 == 1) {
                    cnt++;
                    flag1 = 0;
                }
            }
        }
        else if(x > y) {
            flag1 = 1;
            if(i != 0) {
                if(flag2 == 1) {
                    cnt++;
                    flag2 = 0;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
