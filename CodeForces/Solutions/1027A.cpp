#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;

bool cmp(char ch1, char ch2)

{
    if(ch1 != 'a') {
        char t1 = ch1 - 1;
        if(ch2 != 'a') {
            char t2 = ch2 - 1;
            if(t1 == t2)
                return true;
        }
        if(ch2 != 'z') {
            char t2 = ch2 + 1;
            if(t1 == t2)
                return true;
        }
    }
    if(ch1 != 'z') {
        char t1 = ch1 + 1;
        if(ch2 != 'a') {
            char t2 = ch2 - 1;
            if(t1 == t2)
                return true;
        }
        if(ch2 != 'z') {
            char t2 = ch2 + 1;
            if(t1 == t2)
                return true;
        }
    }

    return false;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        bool chk = 1;
        cin >> s;
        for(ll i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--) {
            if(!cmp(s[i], s[j])) {
                chk = 0;
                break;
            }
        }

        if(chk)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}