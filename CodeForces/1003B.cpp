#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,  b, x;
    cin >> a >> b >> x;
    ll len = a + b;
    if(a > b) {
        ll cnt = 0, cz = 1, co = 0;
        string s = "0";
        ll state = 1;
        while(1) {
            s += (state + '0');
            cnt++;
            if(state)
                co++;
            else
                cz++;
            if(cnt == x)
                break;
            state ^= 1;
        }
        for(ll i = 0; i < s.length(); i++) {
            printf("%c", s[i]);
            if(s[i] == '0' && cz < a) {
                for(ll j = cz + 1; j <= a; j++) {
                    printf("0");
                    cz++;
                }
            }
            if(s[i] == '1' && co < b) {
                for(ll j = co + 1; j <= b; j++) {
                    printf("1");
                    co++;
                }
            }
        }
    }
    else {
        ll cnt = 0, cz = 0, co = 1;
        string s = "1";
        ll state = 0;
        while(1) {
            s += (state + '0');
            cnt++;
            if(state)
                co++;
            else
                cz++;
            if(cnt == x)
                break;
            state ^= 1;
        }
        for(ll i = 0; i < s.length(); i++) {
            printf("%c", s[i]);
            if(s[i] == '0' && cz < a) {
                for(ll j = cz + 1; j <= a; j++) {
                    printf("0");
                    cz++;
                }
            }
            if(s[i] == '1' && co < b) {
                for(ll j = co + 1; j <= b; j++) {
                    printf("1");
                    co++;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
