#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s1[108], s2[109];
ll mark[109], mark2[109];

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> s1[i];
    }

    for(ll i = 1; i <= n; i++) {
        cin >> s2[i];
    }

    ll indx = 0, ans = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            if(mark[j])
                continue;

            if(s1[i] == s2[j]) {
                mark[j] = 1;
                mark2[i] = 1;
                break;
            }
        }
    }
    for(ll i = 1; i <= n; i++) {

        if(mark2[i]) {
            continue;
        }

        ll mn = 1e18;
        for(ll j = 1; j <= n; j++) {
            ll mv = 0;

            if(mark[j])
                continue;

            if(s1[i].length() != s2[j].length())
                continue;

            for(ll k = 0; k < s2[j].length(); k++) {
                if(s1[i][k] != s2[j][k])
                    mv++;
            }

            if(mv < mn) {
                mn = mv;
                indx = j;
            }
        }

        ans += mn;
        mark[indx] = 1;
    }

    cout << ans << endl;
    return 0;
}