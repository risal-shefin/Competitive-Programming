#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    std::ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    ll sum = 0, cnt = 0, ps = 0;
    for(ll i = s.length() - 1; i >= 0; i--) {
        ll x = s[i] - '0';

        sum += x;

        if(sum % 3 == 0) {
            sum = 0;
            ps = 0;
            cnt++;
            //cout << i << " " << "  sdffs " << endl;
            continue;
        }
        else {
            if(i == s.length() - 1) {
                ps += x;
                continue;
            }

            ll rem = sum % 3;
            ll ager = s[i + 1] - '0';
            //cout << ager << "  " << i <<  endl;
            if((sum - ager) % 3 == 0 && ps != 0 && sum > ager) {
                //cout << i << "  " << " hik  " << sum << "  " << ager <<  endl;
                cnt++;
                sum = 0;
                ps = 0;
                continue;
            }
            else if((sum - ps) % 3 == 0) {
                //cout << i << "  " << sum << "  " << ps << endl;
                cnt++;
                sum = 0;
                ps = 0;
                continue;
            }

        }

        ps += x;
    }

    cout << cnt << endl;

    return 0;
}