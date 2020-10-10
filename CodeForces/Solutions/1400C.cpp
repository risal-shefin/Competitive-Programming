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

const ll sz = 1e5 + 10;
char s[sz], res[sz];

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        scanf("%s", s+1);
        ll x; sl(x);

        ll len = strlen(s+1);

        for1(i, len) res[i] = '\0';

        for1(i, len) {
            if(s[i] != '0')
                continue;

            ll prv = i-x, nxt = i+x;

            if(prv >= 1) res[prv] = '0';
            if(nxt <= len) res[nxt] = '0';
        }

        bool ok = 1;
        for1(i, len) {
            if(s[i] == '0')
                continue;

            ll prv = i-x, nxt = i+x;

            if(prv >= 1 && nxt <= len) {
                if(res[prv] == '0' && res[nxt] == '0') {
                    ok = 0;
                    break;
                }

                if(res[prv] != '0') res[prv] = '1';
                if(res[nxt] != '0') res[nxt] = '1';
            }
            else if(prv >= 1) {
                if(res[prv] == '0') {
                    ok = 0;
                    break;
                }

                res[prv] = '1';
            }
            else if(nxt <= len) {
                if(res[nxt] == '0') {
                    ok = 0;
                    break;
                }
                res[nxt] = '1';
            }
            else {
                ok = 0;
                break;
            }
        }

        if(!ok) pf("-1\n");
        else {

            for1(i, len) if(res[i] == '\0') res[i] = '1';

            res[len+1] = '\0';
            pf("%s\n", res+1);
        }
    }

    return 0;
}