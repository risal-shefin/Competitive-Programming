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
pll a[sz], b[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        sl(n), sl(k);

        ll l1, r1;
        sl(l1), sl(r1);

        ll l2, r2;
        sl(l2), sl(r2);

        if(l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        for1(i, n) a[i] = mp(l1, r1);

        for1(i, n) b[i] = mp(l2, r2);

        ll extra = max(0LL, l2-r1);

        ll ans = inf;

        for1(i, n) {
            ll cst = extra * i;

            ll lmax = max(l1, l2), rmin = min(r1, r2);
            ll seg = max(0LL, rmin - lmax), now = seg*i;

            if(now >= k) {
                ans = min(ans, cst);
                continue;
            }

            ll lmin = min(l1, l2), rmax = max(r1, r2);
            ll full = (rmax - lmin) * i;

            if(full >= k) {
                ans = min(ans, cst+(k-now));
                continue;
            }

            cst += (full - now);
            ans = min(ans, cst + 2*(k-full));
        }

        pf("%lld\n", ans);
    }

    return 0;
}