#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll deg[20], cs[20], n;

ll solve(ll pos, ll val)

{
    if(pos > n) {
        return val == 0;
    }

    ll nval = val + deg[pos];
    ll rt = solve(pos + 1, (nval + 360) % 360);
    nval = val - deg[pos];
    rt |= solve(pos + 1, (nval + 360) % 360);

    return rt;
}

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> deg[i];
    }

    ll ans = solve(1, 0);

    if(ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}