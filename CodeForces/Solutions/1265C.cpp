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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll ara[400009];

int main()

{
    ll t;
    sl(t);
    while(t--) {
        ll n;
        sl(n);

        forn(i, n)
            sl(ara[i]);

        ll g = 1, s = 0, b = 0, half = n / 2;
        ll state = 1, val;

        for(ll i = 2; i <= n; i++) {
            if(state == 1) {
                if(ara[i] == ara[1])
                    g++;
                else
                    s = 1, state = 2, val = ara[i];
            }
            else if(state == 2) {
                if(s <= g)
                    s++, val = ara[i];
                else if(val == ara[i])
                    s++;
                else
                    b = 1, state = 3, val = ara[i];
            }
            else{
                if(g+s+b < half || b <= g)
                    b++, val = ara[i];
                else if(val == ara[i]) {
                    while(ara[i] == val)
                        i--, b--;

                    b++;
                    break;
                }
                else
                    break;
            }
        }

        if(!(g > 0 && s > 0 && b > 0) || g+s+b > half || g >= s || g >= b)
            pf("0 0 0\n");
        else
            pf("%lld %lld %lld\n", g, s, b);
    }

    return 0;
}