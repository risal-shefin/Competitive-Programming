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

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll x, y, k;
        sl(x), sl(y), sl(k);

        ll tot = k*y + k, ase = 1, ans = 0;

        while(ase < tot) {

            if(ase <= tot / x) {
                ans += ase;
                ase *= x;
            }
            else {
                ll more = tot - ase;
                ll need = more / (x-1);
                if(more % (x-1) != 0)
                    need++;

                ans += need;
                ase += (need * (x-1));
            }
        }

        pf("%lld\n", ans+k);
    }

    return 0;
}