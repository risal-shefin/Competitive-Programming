#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[105], ans[105];
bool mark[105];

int main()

{
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll indx = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> ara[i];
        if(mark[ ara[i] ] == 0) {
            mark[ ara[i] ] = 1;
            ans[indx++] = i;
        }
    }

    if(indx < k)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(ll i = 0; i < k; i++) {
            if(i != 0)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}