#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1824261409

ll hash1[100009], hash2[100009], pwr[100009];

int main()

{
    pwr[0] = 1;
    for(ll i = 1; i <= 100000; i++) {
        pwr[i] = ( (pwr[i - 1] % mod) * 128) % mod;
    }

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    ll frq;
    cin >> frq;
    for(ll i = 0; i < s1.length(); i++) {
        hash1[i + 1] += ( ( (s1[i] % mod) * (pwr[i] % mod) )  % mod + hash1[i] % mod ) % mod;
    }

    for(ll i = 0; i < s2.length(); i++) {
        hash2[i + 1] += ( ( (s2[i] % mod) * (pwr[i] % mod) ) % mod + hash2[i] % mod) % mod;
    }

    ll lo = 1, hi = s2.length(), ans;
    bool flag = 0;

    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll pref = hash2[mid];
        ll cnt = 0;

        for(ll i = 0; i < s1.length() - (mid - 1); i++) {
            //cout << " jhgjhgghjhgjh " << endl;
            //cout << pwr[i] << "  " << hash1[i + 1 + (mid - 1)] << "  " << hash1[i] << endl;
            ll tmp = ( (hash1[i + 1 + (mid - 1)] - hash1[i]) % mod + mod) % mod;
            //cout << tmp << "  " << pref << "  " << mid << endl;
            ll cmp = (pref * pwr[i]) % mod;
            if(tmp == cmp)
                cnt++;
        }

        if(cnt >= frq) {
            lo = mid + 1;
            flag = 1;
            ans = mid;
        }
        else
            hi = mid - 1;
    }

    if(flag == 1) {
        for(ll i = 0; i < ans; i++) {
            printf("%c", s2[i]);
        }
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");

    return 0;
}