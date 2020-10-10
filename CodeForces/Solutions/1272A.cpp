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
 
ll aa[3], bb[3], cc[3];
 
int main()
 
{
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        sl(a), sl(b), sl(c);
 
        ll ans = inf;
        aa[0] = a-1, aa[1] = a, aa[2] = a+1;
        bb[0] = b-1, bb[1] = b, bb[2] = b+1;
        cc[0] = c-1, cc[1] = c, cc[2] = c+1;
 
        for(ll i = 0; i < 3; i++) {
            for(ll j = 0; j < 3; j++) {
                for(ll k = 0; k < 3; k++) {
                    ans = min(ans, abs(aa[i] - bb[j]) + abs(aa[i] - cc[k]) + abs(bb[j] - cc[k]) );
                }
            }
        }
 
        pf("%lld\n", ans);
    }
 
    return 0;
}