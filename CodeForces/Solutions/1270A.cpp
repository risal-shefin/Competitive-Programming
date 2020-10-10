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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()

{
    ll t;
    sl(t);
    while(t--) {
        ll mx1 = 0, mx2 = 0;
        ll n, k1, k2;
        sl(n), sl(k1), sl(k2);

        for1(i, k1) {
            ll inp;
            sl(inp);
            mx1 = max(mx1, inp);
        }

        for1(i, k2) {
            ll inp;
            sl(inp);
            mx2 = max(mx2, inp);
        }

        if(mx1 > mx2)
            pf("YES\n");
        else
            pf("NO\n");
    }

    return 0;
}