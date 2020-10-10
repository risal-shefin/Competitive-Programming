#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(char a, char b)

{
    return a > b;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    string s;
    ll t;
    cin >> t;
    while(t--) {
        cin >> s;
        ll sum = 0, flag = 0, cnt = 0, idx = -1;
        for(ll i = 0; i < s.length(); i++) {
            sum += (s[i] - '0');

            if(s[i] == '5' || s[i] == '0') {
                flag = 1;
                if(idx == -1)
                    idx = i;
                else if(s[i] < s[idx])
                    idx = i;
            }

            if(s[i] > '0')
                cnt++;
        }

        if(flag == 0) {
            cout << "impossible" << endl;
            continue;
        }
        if(cnt == 0) {
            cout << 0 << endl;
            continue;
        }

        string s2 = "";
        for(ll i = 0; i < s.length(); i++) {
            if(idx == i)
                continue;
            s2 += s[i];
        }

        sort(s2.begin(), s2.end(), cmp);

        if(sum % 3 == 1) {
            bool check = 0;
            for(ll i = s2.length(); i >= 0; i--) {
                ll nm = s2[i] - '0';
                if(nm % 3 == 1) {
                    check = 1;
                    s2.erase(s2.begin() + i);
                    break;
                }
            }

            ll cnt2 = 0;
            if(!check) {
                for(ll i = s2.length(); i >= 0; i--) {
                    ll nm = s2[i] - '0';
                    if(nm % 3 == 2) {
                        s2.erase(s2.begin() + i);
                        cnt2++;
                    }

                    if(cnt2 == 2)
                        break;
                }
            }

            if(check == 0 && cnt2 != 2) {
                cout << "impossible" << endl;
                continue;
            }

        }
        else if(sum % 3 == 2) {
            bool check = 0;
            for(ll i = s2.length(); i >= 0; i--) {
                ll nm = s2[i] - '0';
                if(nm % 3 == 2) {
                    check = 1;
                    s2.erase(s2.begin() + i);
                    break;
                }
            }

            ll cnt1 = 0;
            if(!check) {
                for(ll i = s2.length(); i >= 0; i--) {
                    ll nm = s2[i] - '0';
                    if(nm % 3 == 1) {
                        s2.erase(s2.begin() + i);
                        cnt1++;
                    }

                    if(cnt1 == 2)
                        break;
                }
            }

            if(check == 0 && cnt1 != 2) {
                cout << "impossible" << endl;
                continue;
            }
        }

        if(s2[0] == '0' && s[idx] == '5') {
            cout << "impossible" << endl;
            continue;
        }

        if(s2[0] == '0' && s[idx] == '0') {
            cout << 0 << endl;
            continue;
        }

        cout << s2 << s[idx] << endl;
    }

    return 0;
