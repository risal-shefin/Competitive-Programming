#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt1[30], cnt2[30];
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(ll i = 0; i < s.length(); i++) {
        cnt1[ s[i] - 'a' ]++;
    }
    for(ll j = 0; j < s.length(); j++) {
        cnt2[ t[j] - 'a' ]++;
    }
    for(ll i = 0; i <= 27; i++) {
        if(cnt1[i] != cnt2[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    vector <ll> ans;
    ll cnt = 10000;
    //while(ans.size() <= 10000) {
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] != t[i]) {
            ll indx = -1;
            for(ll j = i + 1; j < s.length(); j++) {
                if(s[j] == t[i])
                    indx = j;
            }
            if(indx == -1)
                break;
            for(ll j = indx - 1; j >= i; j--) {
                ans.push_back(j + 1);
                swap(s[j], s[j + 1]);
            }
            //cout << s << "  " << i << "  " << indx << endl;
        }
    }
    /*if(s == t)
        break;
    }*/
    if(s != t || ans.size() > 10000) {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
