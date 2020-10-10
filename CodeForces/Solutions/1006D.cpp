#include <bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll n;
    cin >> n >> a >> b;
    for(ll i = 0, rev = n - 1; i < n; i++, rev--) {

        if(a[i] == b[i])
            continue;
        if(a[rev] == b[rev])
            continue;

        if(b[i] == b[rev]) {
            swap(a[i], b[i]);
            swap(a[i], a[rev]);
        }
        else {
            if(a[i] == b[rev] || a[rev] == b[i])
                swap(a[i], a[rev]);
        }

        //cout << a << endl << b << endl;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++)
        if(a[i] != b[i])
            ans++;

    cout << ans << endl;

    return 0;
}