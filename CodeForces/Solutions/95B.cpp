#include <bits/stdc++.h>
using namespace std;

#define ll long long

string num, ans = "";
ll cntf = 0, cnts = 0, len;

bool solve(ll pos, ll isLarge)

{
    if(pos == len) return 1;

    if(cntf < len / 2 && (isLarge | num[pos] <= '4') ) {
        cntf++;
        if(solve(pos + 1, isLarge | num[pos] < '4')) {
            ans += "4";
            return 1;
        }
        cntf--;
    }
    if(cnts < len / 2 && (isLarge | num[pos] <= '7') ) {
        cnts++;
        if(solve(pos + 1, isLarge | num[pos] < '7')) {
            ans += "7";
            return 1;
        }
        cnts--;
    }

    return 0;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin >> num;
    ll cnt4 = 0, cnt7 = 0, isLarge = 0;

    if(num.length() & 1)
        len = num.length() + 1;
    else {
        len = num.length();
        string tmp = "";
        for(ll i = 0; i < len / 2; i++)
            tmp += "7";

        for(ll i = len / 2; i < len; i++)
            tmp += "4";

        if(tmp < num)
            len += 2;
    }

    if(len > num.length()) {
        for(ll i = 0; i < len / 2; i++)
            ans += "4";

        for(ll i = len / 2; i < len; i++)
            ans += "7";

        cout << ans << endl;
    }
    else {
        solve(0, 0);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}