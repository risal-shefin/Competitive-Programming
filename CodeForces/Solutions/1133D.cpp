#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, a[200009], b[200009];

map <long double, int> cnt;

int main()

{
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &b[i]);

    int zero = 0;
    for(ll i = 1; i <= n; i++) {
        if(a[i] == 0) {
            if(b[i] == 0)
                zero++;
            continue;
        }
        long double d = -b[i] / (a[i] * 1.0);
        cnt[d]++;
    }

    int mx = zero;
    for(auto it = cnt.begin(); it != cnt.end(); it++) {
        mx = max(mx, zero + (it -> second));
    }

    cout << mx << endl;

    return 0;
}