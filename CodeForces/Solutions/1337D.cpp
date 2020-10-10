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

const ll sz = 1e5 + 10;
ll r[sz], g[sz], b[sz];

inline ll sq(ll x) {return x*x;}

inline ll val(ll x, ll y, ll z) {
    return sq(x-y) + sq(y-z) + sq(z-x);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll nr, ng, nb;
        sl(nr), sl(ng), sl(nb);

        for1(i, nr) sl(r[i]);
        for1(i, ng) sl(g[i]);
        for1(i, nb) sl(b[i]);

        sort(r+1, r+nr+1); sort(g+1, g+ng+1); sort(b, b+nb+1);

        ll ans = inf;
        for1(i, nr) {
            ll lg = lower_bound(g+1, g+ng+1, r[i]) - g;
            if(lg > ng || g[lg] > r[i]) lg--;
            ll ug = upper_bound(g+1, g+ng+1, r[i]) - g;

            ll lb = lower_bound(b+1, b+nb+1, r[i]) - b;
            if(lb > nb || b[lb] > r[i]) lb--;
            ll ub = upper_bound(b+1, b+nb+1, r[i]) - b;

            if(lg > 0 && lb > 0) {
                ans = min(ans, val(r[i], g[lg], b[lb]));
            }
            if(lg > 0 && ub <= nb) {
                ans = min(ans, val(r[i], g[lg], b[ub]) );
            }
            if(ug <= ng && ub <= nb) {
                ans = min(ans, val(r[i], g[ug], b[ub]) );
            }
            if(ug <= ng && lb > 0) {
                ans = min(ans, val(r[i], g[ug], b[lb]) );
            }
        }

        for1(i, ng) {
            ll lr = lower_bound(r+1, r+nr+1, g[i]) - r;
            if(lr > nr || r[lr] > g[i]) lr--;
            ll ur = upper_bound(r+1, r+nr+1, g[i]) - r;

            ll lb = lower_bound(b+1, b+nb+1, g[i]) - b;
            if(lb > nb || b[lb] > g[i]) lb--;
            ll ub = upper_bound(b+1, b+nb+1, g[i]) - b;

            if(lr > 0 && lb > 0) {
                ans = min(ans, val(g[i], r[lr], b[lb]));
            }
            if(lr > 0 && ub <= nb) {
                ans = min(ans, val(g[i], r[lr], b[ub]) );
            }
            if(ur <= nr && ub <= nb) {
                ans = min(ans, val(g[i], r[ur], b[ub]) );
            }
            if(ur <= nr && lb > 0) {
                ans = min(ans, val(g[i], r[ur], b[lb]) );
            }
        }

        for1(i, nb) {
            ll lg = lower_bound(g+1, g+ng+1, b[i]) - g;
            if(lg > ng || g[lg] > b[i]) lg--;
            ll ug = upper_bound(g+1, g+ng+1, b[i]) - g;

            ll lr = lower_bound(r+1, r+nr+1, b[i]) - r;
            if(lr > nr || r[lr] > b[i]) lr--;
            ll ur = upper_bound(r+1, r+nr+1, b[i]) - r;

            if(lg > 0 && lr > 0) {
                ans = min(ans, val(b[i], g[lg], r[lr]));
            }
            if(lg > 0 && ur <= nr) {
                ans = min(ans, val(b[i], g[lg], r[ur]) );
            }
            if(ug <= ng && ur <= nr) {
                ans = min(ans, val(b[i], g[ug], r[ur]) );
            }
            if(ug <= ng && lr > 0) {
                ans = min(ans, val(b[i], g[ug], r[lr]) );
            }
        }

        pf("%lld\n", ans);
    }

    return 0;
}