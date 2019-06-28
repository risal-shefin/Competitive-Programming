#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s;
unordered_map <int, int> m;
vector <ll> num;
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> s;
        ll cnt = 0;
        ll mn = 1e18;
        for(ll i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                cnt++;
            else
                cnt--;
            mn = min(mn, cnt);
        }
        if(cnt > mn && mn < 0)
            continue;
        if(m.find(cnt) == m.end())
            num.pb(cnt);
        m[cnt]++;
    }
    sort(num.begin(), num.end());
    ll ans = 0;
    for(ll i = 0; i < num.size(); i++) {
        if(num[i] < 0)
            continue;
        ll lft = num[i];
        ll rgt = -num[i];
        if(num[i] == 0) {
            ans = m[ num[i] ] / 2;
        }
        else {
            ans += min(m[lft], m[rgt]);
        }
    }
    cout << ans << endl;
    return 0;
}
