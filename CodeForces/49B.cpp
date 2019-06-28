#include <bits/stdc++.h>
using namespace std;
#define ll long long
string make_string(ll num)
{
    string ans = "";
    while(num != 0) {
        ll tmp = num % 10;
        num /= 10;
        ans += (tmp + '0');
    }
    reverse(ans.begin(), ans.end());
    //cout << ans << endl;
    return ans;
}
ll sum(string s, string s1, ll mx)
{
    ll a, b, sm, carry = 0;
    ll cnt = 0;
    reverse(s.begin(), s.end());
    reverse(s1.begin(), s1.end());
    ll len = max(s.length(), s1.length());
    for(ll i = 0; i < len; i++) {
        if(i >= s.length())
            a = 0;
        else
            a = s[i] - '0';
        if(i >= s1.length())
            b = 0;
        else
            b = s1[i] - '0';
        sm = a + b + carry;
        carry = sm / mx;
        sm = sm % mx;
        cnt++;
    }
    if(carry > 0)
        cnt++;
    return cnt;
}
int main()
{
    ll num1 , num2;
    cin >> num1 >> num2;
    ll mul = num1 * num2;
    string a = make_string(num1), b = make_string(num2);
    ll mx = 0;
    for(ll i = 0; i < a.length(); i++) {
        ll num = a[i] - '0';
        mx= max(mx, num);
    }
    for(ll i = 0; i < b.length(); i++) {
        ll num = b[i] - '0';
        //cout << num << endl;
        mx= max(mx, num);
    }
    mx++;
    if(mx == 1) {
        printf("1\n");
        return 0;
    }
    //cout << a << b << mx << endl;
    ll cnt = sum(a, b, mx);
    printf("%lld\n", cnt);
    return 0;
}
