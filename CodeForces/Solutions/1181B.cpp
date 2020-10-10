#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s, s1, s2;
ll n, half;

string sum(string &s1, string &s2)

{
    string res = "";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    ll carry = 0;
    for(ll i = 0; i < max(s1.length(), s2.length()); i++) {
        ll num1 = 0, num2 = 0;
        if(i < s1.length()) num1 = s1[i] - '0';
        if(i < s2.length()) num2 = s2[i] - '0';

        ll s = num1 + num2 + carry;
        carry = s / 10;
        s %= 10;

        res.push_back(s + '0');
    }
    if(carry > 0) res.push_back(carry + '0');

    reverse(res.begin(), res.end());

    return res;
}

string mn(string &s1, string &s2)

{
    if(s1.length() < s2.length()) return s1;
    else if(s1.length() > s2.length()) return s2;
    else {
        if(s1 < s2) return s1;
        else return s2;
    }
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> s;
    half = n / 2;

    if(n % 2 == 0) {
        if(s[half] == '0') {
            ll frst = 0, last = n;
            for(ll i = half; i >= 0; i--) {
                if(s[i] != '0') {
                    frst = i;
                    break;
                }
            }
            for(ll i = half; i < n; i++) {
                if(s[i] != '0') {
                    last = i;
                    break;
                }
            }

            string s1 = "", s2 = "";
            for(ll i = 0; i < frst; i++)
                s1.push_back(s[i]);
            for(ll i = frst; i < n; i++)
                s2.push_back(s[i]);

            string sum1 = sum(s1, s2);

            s1 = "", s2 = "";
            for(ll i = 0; i < last; i++)
                s1.push_back(s[i]);
            for(ll i = last; i < n; i++)
                s2.push_back(s[i]);

            string sum2 = sum(s1, s2);

            cout << mn(sum1, sum2) << endl;
        }
        else {
            string s1 = "", s2 = "";
            for(ll i = 0; i < half; i++)
                s1.push_back(s[i]);
            for(ll i = half; i < n; i++)
                s2.push_back(s[i]);

            cout << sum(s1, s2) << endl;
        }
    }
    else {
        string ans = "";
        ll nhalf = half + 1;
        if(s[half] == '0') {
            ll frst = 0, last = n;
            for(ll i = half; i >= 0; i--) {
                if(s[i] != '0') {
                    frst = i;
                    break;
                }
            }
            for(ll i = half; i < n; i++) {
                if(s[i] != '0') {
                    last = i;
                    break;
                }
            }

            string s1 = "", s2 = "";
            for(ll i = 0; i < frst; i++)
                s1.push_back(s[i]);
            for(ll i = frst; i < n; i++)
                s2.push_back(s[i]);

            string sum1 = sum(s1, s2);

            s1 = "", s2 = "";
            for(ll i = 0; i < last; i++)
                s1.push_back(s[i]);
            for(ll i = last; i < n; i++)
                s2.push_back(s[i]);

            string sum2 = sum(s1, s2);
            ans = mn(sum1, sum2);
        }
        if(s[nhalf] == '0') {
            ll frst = 0, last = n;
            for(ll i = nhalf; i >= 0; i--) {
                if(s[i] != '0') {
                    frst = i;
                    break;
                }
            }
            for(ll i = nhalf; i < n; i++) {
                if(s[i] != '0') {
                    last = i;
                    break;
                }
            }

            string s1 = "", s2 = "";
            for(ll i = 0; i < frst; i++)
                s1.push_back(s[i]);
            for(ll i = frst; i < n; i++)
                s2.push_back(s[i]);

            string sum1 = sum(s1, s2);

            s1 = "", s2 = "";
            for(ll i = 0; i < last; i++)
                s1.push_back(s[i]);
            for(ll i = last; i < n; i++)
                s2.push_back(s[i]);

            string sum2 = sum(s1, s2);

            string tmp = mn(sum1, sum2);
            if(ans.length() == 0) ans = tmp;
            else ans = mn(ans, tmp);
        }

        if(s[half] != '0' && s[nhalf] != '0') {
            string s1 = "", s2 = "";
            for(ll i = 0; i < half; i++)
                s1.push_back(s[i]);
            for(ll i = half; i < n; i++)
                s2.push_back(s[i]);

            string sum1 = sum(s1, s2);

            s1 = "", s2 = "";
            for(ll i = 0; i < nhalf; i++)
                s1.push_back(s[i]);
            for(ll i = nhalf; i < n; i++)
                s2.push_back(s[i]);

            string sum2 = sum(s1, s2);

            string tmp = mn(sum1, sum2);
            if(ans.length() == 0) ans = tmp;
            else ans = mn(ans, tmp);
        }

        cout << ans << endl;
    }

    return 0;
}