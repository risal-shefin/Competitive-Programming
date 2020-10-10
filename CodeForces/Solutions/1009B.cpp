#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll z[100009];

int main()

{
    string s;
    std::ios_base::sync_with_stdio(false);

    cin >> s;

    ll flag1 = 0, flag2 = 0;

    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == '1')
            flag1++;
        else if(s[i] == '2')
            flag2++;
        else
            z[ flag2 ]++;
    }

    for(ll i = 1; i <= z[0]; i++)
        cout << "0";
    for(ll i = 1; i <= flag1; i++)
        cout << "1";
    for(ll i = 1; i <= flag2; i++) {
        cout << "2";
        for(ll j = 1; j <= z[ i ]; j++)
            cout << "0";
    }
    cout << endl;

    return 0;
}