#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll cnt[15] = {};
    ll k, in;
    cin >> k;
    for(ll i = 1; i <= 16; i++) {
        char ch;
        scanf(" %c", &ch);
        if(ch == '.')
            continue;
        else
            in = ch - '0';
        cnt[in]++;
    }
    for(ll i = 1; i <= 9; i++) {
        if(cnt[i] > 2 * k) {
            //cout << cnt[i] << "  " << i << endl;
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
