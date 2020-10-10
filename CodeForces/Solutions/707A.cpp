#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, m;
    cin >> n >> m;
    char ch;
    bool test = 0;

    for(int  i = 1; i <= n; i++) {
        for(int j  = 1; j <= m; j++) {
        scanf(" %c", &ch);
        if( ! (ch == 'W' || ch == 'B' || ch == 'G') ) {
            test = 1;
        }
        }
    }

    if(test) {
        cout << "#Color" << endl;
    }
    else {
        cout << "#Black&White" << endl;
    }

    return 0;
}