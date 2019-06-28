#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(val) scanf("%lld", &val)
#define inf 2e18
int main()
{
    ll n;
    sl(n);
    string s;
    cin >> s;
    if(n == 1) {
        if(s == "1") {
            printf("Yes\n");
            return 0;
        }
        else {
            printf("No\n");
            return 0;
        }
    }
    if(n == 2) {
        if(s == "10" || s == "01") {
            printf("Yes\n");
            return 0;
        }
        else {
            printf("No\n");
            return 0;
        }
    }
    bool chk = 1;
    ll prv;
    for(ll i = 0; i < s.length(); i++) {
        if(i > 0) {
            ll tmp = s[i] - '0';
            if(tmp == prv && prv == 1) {
                chk = 0;
                break;
            }
        }
        prv = s[i] - '0';
    }
    if(!chk) {
        printf("No\n");
        return 0;
    }
    bool checker = 1;
    for(ll i = 1; i < s.length() - 1; i++) {
        prv = s[i - 1] - '0';
        ll now = s[i] - '0';
        ll nxt = s[i + 1] - '0';
        if(prv == 0 && now == 0 && nxt == 0) {
            checker = 0;
            break;
        }
    }
    if(s[ s.length() - 1] == '0' && s[ s.length() - 2] == '0') {
        checker = 0;
    }
    if(s[0] == '0' && s[1] == '0') {
        checker = 0;
    }
    if(checker) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}
