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

ll ara[200009];

int main()

{
    ll t;
    sl(t);
    while(t--) {
        ll n;
        sl(n);

        for1(i, n)
            sl(ara[i]);

        bool chk = 0;
        ll l, r;
        for1(i, (n-1)) {
            ll diff = abs(ara[i] - ara[i+1]);
            if(diff >= 2) {
                chk = 1;
                l = i, r = i+1;
                break;
            }
        }

        if(!chk)
            pf("NO\n");
        else {
            pf("YES\n%lld %lld\n", l, r);
        }
    }

    return 0;
}