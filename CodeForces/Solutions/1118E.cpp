#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll m[200009], w[200009];

int main()

{
    ll n, k, indx = 0;
    cin >> n >> k;

    for(ll i = 1; i <= k; i++) {
        for(ll j = i + 1; j <= k; j++) {
            if(i == j)
                continue;

            m[indx] = i;
            w[indx++] = j;

            m[indx] = j;
            w[indx++] = i;

//            cout << i << "  " << j << endl;
//            cout << indx << endl;

            if(indx >= n)
                break;
        }

        if(indx >= n)
            break;
    }

    if(indx < n) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for(ll i = 0; i < n; i++) {
            printf("%lld %lld\n", m[i], w[i]);
        }
    }

    return 0;
}