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

char s[509];
ll ara[1000009];
const ll mod = 1e9 + 7;

int main()

{
    ll t;
    sl(t);
    while(t--) {
        ll x;
        sl(x);
        scanf("%s", s);

        ll id = 0, len = strlen(s);
        for(ll i = 0; i < len; i++)
            ara[id++] = s[i] - '0';

        for(ll i = 1; i <= x; i++) {

            ll c = ( (len - i) % mod + mod) % mod;
            ll p = (c * ara[i-1]) % mod;
            len = (i + p) % mod;

            ll lim = id-1, rnd = 2;
            for(ll j = i; id < x && rnd <= ara[i-1]; j++) {
                ara[id++] = ara[j];

                if(j == lim) j = i-1, rnd++;
            }
        }

        pf("%lld\n", len);
    }

    return 0;
}