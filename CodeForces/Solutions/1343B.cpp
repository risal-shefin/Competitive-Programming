#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        ll h = n / 2;
        if(h & 1) {
            pf("NO\n");
            continue;
        }

        pf("YES\n");
        ll sum = 0;
        for(ll i = 1, j = 2; i <= h; i++, j += 2) {
            if(i != 1) pf(" ");
            pf("%lld", j);
            sum += j;
        }

        ll sum2 = 0;
        for(ll i = 1, j = 1; i < h; i++, j+=2) {
            pf(" %lld", j);
            sum2 += j;
        }

        pf(" %lld\n", abs(sum-sum2));
    }

    return 0;
}