#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    string me = "";
    me += s[0];
    ll cnt = 1, last = 0;
    while(cnt < k) {

        bool chk = 0;
        for(ll i = last + 1; i < s.length(); i++) {
            if(s[i] > me[ me.length() - 1] + 1) {
                me += s[i];
                chk = 1;
                last = i;
                cnt++;
                break;
            }
        }

        if(chk == 0)
            break;
    }

    if(me.length() < k) {
        cout << "-1" << endl;
    }
    else {
        ll sum = 0;

        //cout << me << endl;
        for(ll i = 0; i < me.length(); i++) {
            sum += ( me[i] - 'a' + 1);
        }

        cout << sum << endl;
    }

    return 0;
}