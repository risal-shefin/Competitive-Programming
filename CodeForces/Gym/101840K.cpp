#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

int main()

{
    freopen("katryoshka.in", "r", stdin);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        ll mn = min(n, m);
        mn = min(mn, k);

        ll cnt = mn;
        n -= mn, m -= mn, k -= mn;
        ll tn = n / 2;
        mn = min(tn, k);
        cnt += mn;

        printf("Case %lld: %lld\n", ++caseno, cnt);
    }

    return 0;
}