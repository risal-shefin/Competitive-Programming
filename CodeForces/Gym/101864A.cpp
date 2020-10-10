#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map <ll, ll> pw;

int main()

{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pw[0] = 1;
    for(ll i = 1; i <= 60; i++) {
        pw[i] = pw[i - 1] * 2;
    }

    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll x, least, n;
        scanf("%lld %lld %lld", &x, &least, &n);

        ll cnt = 0;
        if(least < x)
            cnt += (x - least);

        ll tot = n - least + 1;
        printf("Case %lld: ", ++caseno);
        if(x % 2 == 0) {
            if(cnt == 0) {
                printf("0/1\n");
                continue;
            }

            ll div = __gcd(cnt, tot);
            ll p = cnt / div;
            ll q = tot / div;
            printf("%lld/%lld\n", p, q);

            continue;
        }

        if(n <= 3) {
            if(x == 1) {

                if(least == 1)
                    cnt = min(n, 2LL);
                if(least == 2)
                    cnt = 1;
            }
            if(x == 3 && n == 3)
                cnt++;

            ll div = __gcd(cnt, tot);
            ll p = cnt / div;
            ll q = tot / div;
            printf("%lld/%lld\n", p, q);

            continue;
        }

        bool fir = 1;
        for(ll i = 0; i <= 60; i++) {
            if(pw[i] < x || pw[i] < least)
                continue;

            if(pw[i] > n) {
                ll prv = pw[i - 1];
                ll dist = n - prv + 1;
                ll dist2 = x / 2;
                if(dist * 2 > x && prv + dist2 >= least)
                    cnt++;
                break;
            }

            if(fir) {
                ll prv = pw[i - 1];
                ll dist = x / 2;
                fir = 0;
                if(prv + dist < least)
                    continue;
            }

            //cout << pw[i] << "  dddd " << endl;
            cnt++;
        }

            ll div = __gcd(cnt, tot);
            ll p = cnt / div;
            ll q = tot / div;
            printf("%lld/%lld\n", p, q);
    }

    return 0;
}