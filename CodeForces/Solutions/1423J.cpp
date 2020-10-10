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

//    m = P(2) = a_0 + 2a_1 + 2^2a_2 + 2^3a_3 + 2^4a_4 + 2^5a_5 + 2^6a_6 + 2^7a_7 + .....
// => m = (a_0 + 8a_3 + 8^2a_6+..) + 2(a_1 + 8a_4 + 8^2a_7+..) + 4(a_2 + 8a_5 + 8^2a_8 + ...)
// => m = X + 2Y + 4Z
// X, Y, Z can be any non-negative integer (since the coefficients a_i can be between 0 and 7,
// and X, Y, Z can be represented in base 8 like this).

const ll mod = 1e9 + 7;

int main()
{
    ll t; sl(t);

    while(t--) {
        ll m; sl(m);

        ll elem = m / 4;

        ll bad;
        if(elem % 2 == 0)
            bad = ( (elem/2) % mod * ( (elem+1) % mod) ) % mod;
        else
            bad = (((elem+1)/2) % mod * (elem % mod) ) % mod;

        bad = (bad * 2) % mod;

        ll way = ((elem+1) % mod * ( (m/2) % mod) ) % mod;

        way = (way + elem+1) % mod;

        way -= bad;
        if(way < 0) way += mod;

        pf("%lld\n", way);
    }

    return 0;
}