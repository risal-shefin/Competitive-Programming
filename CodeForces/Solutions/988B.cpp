#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(x) scanf("%lld", &x)

string ara[105];

bool cmp(string a, string b)

{
    return a.length() < b.length();
}

int main()

{
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> ara[i];

    if(n == 1) {
        cout << "YES" << endl;
        cout << ara[1] << endl;
        return 0;
    }

    sort(ara + 1, ara + n + 1, cmp);

    bool chk = 1;
    for(ll i = 1; i < n; i++) {


        ll len = ara[i].length();
        bool chk2 = 0;
        for(ll j = 0; j < ara[i + 1].length() - len + 1; j++) {

            string tmp = "";
            for(ll k = j; k < j + len; k++) {
                tmp += ara[i + 1][k];
            }

            //cout << "  " << tmp << endl;
            if(tmp == ara[i]) {
                chk2 = 1;
                //cout << tmp << "  " << ara[i] << endl;
                break;
            }
        }

        if(chk2 == 0) {
            chk = 0;
            break;
        }
    }

    if(!chk) {
        cout << "NO" << endl;
        return 0;
    }

    else {
        cout << "YES" << endl;
        for(ll i = 1; i <= n; i++) {
            cout << ara[i] << endl;
        }
    }

    return 0;
}