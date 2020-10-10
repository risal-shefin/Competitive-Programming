#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, cf = 0, cl = 0, sf = 0, sl = 0;
    cin >> n >> s;

    for(ll i = 0; i < s.length(); i++) {
        if(i < (n / 2)) {
            if(s[i] == '?')
                cf++;
            else
                sf += (s[i] - '0');
        }
        else {
            if(s[i] == '?')
                cl++;
            else
                sl += (s[i] - '0');
        }
    }

    if(sf < sl) {
        swap(cf, cl), swap(sf, sl);
    }
    ll diff = sf - sl;

    if(cf > cl) {
        cout << "Monocarp" << endl;
        return 0;
    }
    else {
        cl -= cf;

        ll b = cl / 2;
        if(cl % 2 != 0)
            b++;

        ll m = cl - b;

        if(m * 9 > diff) {
            cout << "Monocarp" << endl;
        }
        else if(b * 9 >= diff) {
            cout << "Bicarp" << endl;
        }
        else {
            cout << "Monocarp" << endl;
        }
    }

    return 0;
}