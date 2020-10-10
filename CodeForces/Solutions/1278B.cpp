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
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        ll a, b;
        sl(a), sl(b);
 
        if(a == b) {
            pf("0\n");
            continue;
        }
 
        ll d = abs(a - b), sum = 0, ans;
 
        for(ll i = 1; i <= 1000000; i++) {
            sum += i;
            ll now = sum + d;
            if(now & 1 || now / 2 < d)
                continue;
 
            ans = i;
            break;
        }
 
        pf("%lld\n", ans);
 
    }
    return 0;
}