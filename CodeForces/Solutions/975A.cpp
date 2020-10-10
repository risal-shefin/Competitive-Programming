#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

char s[1009];

int main()

{
    set <string> root;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%s", s);
        unordered_map <char, bool> check;
        string tmp = "";
        for(ll j = 0; s[j] != '\0'; j++) {
            if(check[ s[j] ] == 0) {
                check[ s[j] ] = 1;
                tmp += s[j];
            }
        }
        sort(tmp.begin(), tmp.end());
        root.insert(tmp);
    }

    cout << root.size() << endl;

    return 0;
}