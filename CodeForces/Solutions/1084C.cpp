#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll cs[100009];
string s;
ll ans = 0;

void solve(ll pos)

{
    if(pos >= s.length())
        return;

    ll cnta = 0, ret;
    if(s[pos] == 'a') {

        for(; pos < s.length(); pos++) {
            if(s[pos] == 'a')
                cnta++;
            else if(s[pos] == 'b')
                break;
        }
        solve(pos);
        ll tmp = 0;
        //cout << ans << " " << cnta << " " << pos << endl;
        tmp = (ans * cnta) % mod;
        tmp = (tmp + cnta) % mod;
        ans = (ans + tmp) % mod;
        //cout << ans << endl;
        //ans = (ans + ret) % mod;
    }
    else
        solve(pos + 1);

    return;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin >> s;
    ll cnt = 0;

    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            cnt++;
            cs[i + 1] = 1;
        }
    }

    for(ll i = 1; i <= s.length(); i++)
        cs[i] += cs[i - 1];

    solve(0);


    cout << ans << endl;

    return 0;
}