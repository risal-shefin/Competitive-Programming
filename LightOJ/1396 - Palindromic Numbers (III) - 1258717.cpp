#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string s2 = "", s3 = "", check = "", s4, me;
char in[100009];
int main()
{
    //freopen("out.txt", "w", stdout);
    //std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--)
    {
        scanf("%s", in);
        s = string(in, strlen(in));
        cout << "Case " << ++caseno << ": ";
        ll len = s.length();
        if(len == 1) {
            if(s == "9")
                cout << "11" << endl;
            else
                cout << (char)(s[0] + 1) << endl;
              continue;
        }
          s2 = "", s3 = "", check = "";
        ll tmp = len / 2;
        if(len % 2 == 0) {
              for(ll i = 0; i < tmp; i++) {
                s2 += s[i];
                check += s[i];
            }
              s4 = check;
            reverse(s4.begin(), s4.end());
            check += s4;
            if(check > s) {
                cout << check << endl;
                continue;
            }
        }
        else {
            for(ll i = 0; i <= tmp; i++) {
                s2 += s[i];
                if(i != tmp)
                    check += s[i];
            }
            s4 = check;
            reverse(s4.begin(), s4.end());
            check = check + s[tmp] + s4;
            if(check > s) {
                cout << check << endl;
                continue;
            }
        }
          ll carry = 0;
        for(ll i = s2.length() - 1; i >= 0; i--) {
            ll num = s2[i] - '0';
            num++;
            carry = num / 10;
            num = num % 10;
            s2[i] = (num + '0');
            if(carry == 0)
                break;
        }
        if(carry)
            s3 = "1";
        s2 = s3 + s2;
          ll len2 = s2.length();
        if(len % 2 != 0 && carry == 0)
            len2--;
        if(len % 2 == 0 && carry)
            len2--;
        if(len % 2 != 0 && carry)
            len2 -= 2;
        //if(len )
        me = "";
        for(ll i = 0; i < len2; i++)
            me += s2[i];
        reverse(me.begin(), me.end());
        s2 += me;
        cout << s2 << endl;
    }
      return 0;
}
