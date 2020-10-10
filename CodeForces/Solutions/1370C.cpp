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

bool solve(ll n, bool state)
{
    if(n == 1) return !state;
    if(n == 2 || n & 1) return state;

    bool ret = !state;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i != 0)
            continue;

        ll d1 = i, d2 = n / i;
        if(d1 % 2 == 0 && d2 % 2 == 0)
            continue;

        if(d2 & 1) swap(d1, d2);

        bool got = solve(d2, state^1);

        if(state) ret |= got;
        else ret &= got;
    }

    return ret;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        si(n);

        if(n <= 1) {
            pf("FastestFinger\n");
            continue;
        }
        else if(n & 1 || n == 2) {
            pf("Ashishgup\n");
            continue;
        }

        bool got = solve(n, 1);
        if(got) pf("Ashishgup\n");
        else    pf("FastestFinger\n");
    }

    return 0;
}