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
 
set <int> st;
map <int, int> cnt;
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        st.clear(), cnt.clear();
 
        ll n, ans = 0;
        sl(n);
        forn(i, n) {
            ll inp;
            sl(inp);
            if(inp & 1)
                continue;
 
            //cnt[inp]++;
            st.insert(-inp);
        }
 
        for(auto it = st.begin(); it != st.end();) {
            ll now = -(*it);
            ll prv = now;
 
            ans++;
            now /= 2;
            if(!(now & 1)) {
                st.insert(-now);
            }
 
            it = st.upper_bound(-prv);
        }
 
        pf("%lld\n", ans);
    }
 
    return 0;
}