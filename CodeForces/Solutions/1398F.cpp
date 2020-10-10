// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
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
#define inf (1LL << 30)
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

const ll sz = 1e6 + 10;
char s[sz];
ll oneStop[sz], oneStart[sz], zeroStop[sz], zeroStart[sz];

int main()
{
    ll n;
    si(n);
    scanf("%s", s+1);

    for1(i, n) {
        if(s[i] == '0')
            continue;

        ll stop;
        for(ll j = i; j <= n; j++) {
            if(s[j] == '0')
                break;

            stop = j;
        }

        for(ll j = i; j <= stop; j++) oneStop[j] = stop, oneStart[j] = i;

        i = stop;
    }

    for1(i, n) {
        if(s[i] == '1')
            continue;

        ll stop;
        for(ll j = i; j <= n; j++) {
            if(s[j] == '1')
                break;

            stop = j;
        }

        for(ll j = i; j <= stop; j++) zeroStop[j] = stop, zeroStart[j] = i;

        i = stop;
    }

    for(ll x = 1; x <= n; x++) {

        ll tot = 0, prv = 0;
        for1(i, n) {

            ll lone = max(prv+1, oneStart[i]), rone = oneStop[i];
            ll lzero = max(prv+1, zeroStart[i]), rzero = zeroStop[i];

            ll start = inf;
            if(rone - lone + 1 >= x) start = min(start, lone);
            if(rzero - lzero + 1 >= x) start = min(start, lzero);

            if(start == inf) {
                prv = i, i = i+x - 1;
                continue;
            }

            tot++, i = start + x - 1;
            prv = i;
        }

        if(x != 1) pf(" ");
        pf("%d", tot);
    }
    pn;

    return 0;
}