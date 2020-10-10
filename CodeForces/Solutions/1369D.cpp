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

const ll sz = 2e6 + 10, mod = 1e9 + 7;
ll newNode[sz], useClaw[sz];

int main()
{
    newNode[1] = 1, newNode[2] = 1;
    useClaw[1] = 0, useClaw[2] = 0;

    for(ll i = 3; i < sz; i++) newNode[i] = (newNode[i-1] + 2*newNode[i-2]) % mod;
    for(ll i = 3; i < sz; i++) useClaw[i] = (newNode[i-2] + useClaw[i-3]) % mod;

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);
        pf("%lld\n", (useClaw[n] * 4) % mod);
    }

    return 0;
}