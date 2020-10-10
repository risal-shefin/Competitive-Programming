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
#define inf (1LL << 61)
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

const ll sz = 1e5 + 10, mod = 1e9 + 7;
vector <int> dv[sz];
int ara[sz];

ll fastPow(ll x, ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret % mod;
}


int main()
{
    for1(i, sz-1) {
        for(ll j = i; j < sz; j += i)
            dv[j].pb(i);
    }

    ll n, mx = 0; sl(n);
    for1(i, n) si(ara[i]), mx = max((ll)ara[i], mx);

    sort(ara+1, ara+n+1);

    ll ans = 0;

    for(ll lcm = 1; lcm <= mx; lcm++) {

        ll prv = n, way = 1;
        for(ll i = dv[lcm].size() - 1; i >= 0; i--) {

            ll num = dv[lcm][i];
            ll last = lower_bound(ara+1, ara+n+1, num) - ara;

            ll rng = prv-last+1;

            ll now = fastPow(i+1, rng);

            if(i == dv[lcm].size() - 1) {
                now -= fastPow(i, rng);
                if(now < 0) now += mod;
            }

            way = (way * now) % mod;
            prv = last-1;
        }

        ans = (ans + way) % mod;
    }

    cout << ans << EL;

    return 0;
}