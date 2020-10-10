#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mod 3367900313

ll hash1[1009], hash2 = 0, pwr[1009];

int main()

{
    std::ios_base::sync_with_stdio(false);

    pwr[0] = 1;
    for(ll i = 1; i <= 1005; i++) {
        pwr[i] = pwr[i - 1] * 101;
    }

    string s, t;
    ll n, m, q;
    cin >> n >> m >> q;
    cin >> s >> t;

    for(ll i = 0; i < s.length(); i++)
        hash1[i + 1] = ( hash1[i] * 101) + (s[i] - 'a' + 1);

    for(ll i = 0; i < t.length(); i++)
        hash2 = (hash2 * 101) + (t[i] - 'a' + 1);

    while(q--) {
        ll x, y;
        cin >> x >> y;

        ll ans = 0;
        for(ll i = x; i + t.length() - 1 <= y; i++) {
            ll hsh = hash1[i + t.length() - 1] - (hash1[i - 1] * pwr[t.length()] );
            if(hsh == hash2)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}