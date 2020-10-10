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

const ll sz = 1e5 + 10;

struct info {
    ll s, id;
} ara[sz];

const bool operator <(const info &a, const info &b)
{
    return a.s < b.s;
}

ll a[sz], b[sz];

int main()
{
    ll n;
    sl(n);

    for1(i, n) sl(ara[i].s), ara[i].id = i;

    sort(ara+1, ara+n+1);

    ll lim = n/3;
    if(n % 3 != 0) lim++;

    for1(i, lim) {
        a[ ara[i].id ] = ara[i].s;
        b[ ara[i].id ] = 0;
    }

    for(ll i = lim+1; i <= 2*lim; i++) {
        a[ ara[i].id ] = 0;
        b[ ara[i].id ] = ara[i].s;
    }

    for(ll i = 2*lim + 1, k = lim; i <= n; i++, k--) {
        a[ ara[i].id ] = ara[i].s - k;
        b[ ara[i].id ] = k;
    }

    cout << "YES" << EL;
    for1(i, n) pf("%lld ", a[i]);
    pn;

    for1(i, n) pf("%lld ", b[i]);
    pn;

    return 0;
}