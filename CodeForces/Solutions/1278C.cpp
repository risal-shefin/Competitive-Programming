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
 
ll a[100009];
ll b[100009], red[100009], bl[100009];
unordered_map <ll, ll> check;
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        ll n;
        sl(n);
 
        forn(i, n)  {
            sl(a[i]);
 
            red[i] = bl[i] = 0;
        }
 
        forn(i, n) {
            sl(b[i]);
 
            if(b[i] == 1)
                red[i] = 1;
            else
                bl[i] = 1;
        }
 
        ll ans = 2*n;
        check[red[n] - bl[n]] = n;
        rep(i, (n-1)) {
            red[i] += red[i+1];
            bl[i] += bl[i+1];
 
            ll diff = red[i] - bl[i];
            check[diff] = i;
 
            if(diff == 0)
                ans = min(ans, n + i - 1);
        }
 
        ll rd = 0, be = 0;
        if(red[1] == bl[1]) ans = n;
        forn(i, n) {
            if(a[i] == 1)
                rd++;
            else
                be++;
 
            ll diff = rd - be;
            //cout << i << " " << diff << endl;
            if(diff == 0)
                ans = min(ans, (n - i) + n);
 
            if(check.find(-diff) != check.end()) {
                ll bad = check[-diff] - 1 + (n - i);
                ans = min(ans, bad);
            }
        }
 
        pf("%lld\n", ans);
 
        check.clear();
 
    }
 
    return 0;
}