#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dgt[8], cs[1000009];
bool mark[100009];

int main()

{
    mark[1] = 1;
    mark[0] = 1;
    for(ll i = 3; i * i <= 100000; i += 2) {
        if(mark[i] == 0) {
            for(ll j = i * i; j <= 100000; j += i + i) {
                mark[j] = 1;
            }
        }
    }

    for(ll i = 4; i <= 100000; i += 2)
        mark[i] = 1;

    for(ll i = 1; i <= 100000; i++) {

        ll nm = i, indx = 0;
        while(nm != 0) {
            ll rem = nm % 10;
            nm /= 10;
            dgt[indx++] = rem;
        }

        reverse(dgt, dgt + indx);
        ll rng = (1 << indx) - 1;

        bool Sprime = 1;
        for(ll j = 1; j <= rng; j++) {
            ll num = 0;
            for(ll k = indx - 1; k >= 0; k--) {
                if( (j >> k) & 1)
                    num = num * 10 + dgt[k];
            }
            if(mark[num] == 0) {
                Sprime = 0;
                break;
            }
        }

        if(Sprime)
            cs[i] = 1;
    }

    for(ll i = 1; i <= 100000; i++)
        cs[i] += cs[i - 1];

    ll t;
    cin >> t;

    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if(a > b)
            swap(a, b);

        printf("%lld\n", cs[b] - cs[a - 1]);
    }

    return 0;
}
