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

        bool pos = 0;
        ll mx = -inf, sum = 0;
        for1(i, n) {
            ll inp;
            sl(inp);

            if(i == 1) {
                mx = max(mx, inp);
                if(inp > 0) pos = 1;
                else pos = 0;
            }
            else {
                bool now = 0;
                if(inp > 0) now = 1;

                if(pos == now) mx = max(mx, inp);
                else {
                    sum += mx;
                    mx = inp;
                    pos = now;
                }
            }
        }
        sum += mx;

        pf("%lld\n", sum);
    }

    return 0;
}