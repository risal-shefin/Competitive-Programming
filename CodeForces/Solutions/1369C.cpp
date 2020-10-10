// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;
ll ara[sz], w[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        sl(n), sl(k);

        for1(i, n) sl(ara[i]);
        sort(ara+1, ara+n+1);

        for1(i, k) sl(w[i]);
        sort(w+1, w+k+1);

        ll ptr1 = 1, ptr2 = n, sum = 0;
        for1(i, k) {
            ll need = w[i] - 1;
            sum += ara[ptr2];
            if(need == 0) sum += ara[ptr2];
            ptr2--;

            w[i]--;
        }

        rep1(i, k) {
            if(w[i] == 0)
                continue;

            for(ll j = 1; j <= w[i]; j++) {
                if(j == 1)
                    sum += ara[ptr1];

                ptr1++;
            }
        }

        pf("%lld\n", sum);
    }

    return 0;
}