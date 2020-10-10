#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define eps 1e-6
ll a[1009], b[1009];

int main()

{
    //std::ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &b[i]);

    double lo = 0.0000000000001, hi = 1000000009, ans = -1;
    ll cnt = 1;
    while(cnt <= 100) {
        double mid = (lo + hi) / 2;

        double tot = mid + m;

        bool chk = 1;
        for(ll i = 1; i < n; i++) {
            double need = tot / a[i];
            tot -= need;
            need = tot / b[i + 1];
            tot -= need;
        }

        double need = tot / a[n];
        tot -= need;
        need = tot / b[1];
        tot -= need;

        if(tot < m) {
            lo = mid;
        }
        else {
            ans = mid;
            hi = mid;
        }

        cnt++;
    }

    if(ans < 0)
        cout << ans << endl;
    else
        printf("%0.7f\n", ans);

    return 0;
}