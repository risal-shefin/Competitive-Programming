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
#define inf (1LL << 62)
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

const ll sz = 1e3 + 10;
ll ara[2*sz];
vector <pll> ans;
vector <ll> odd, ev;

int main()
{
    ll t;
    sl(t);
    while(t--) {
        ll n;
        sl(n);

        ll m = 2*n;
        for1(i, m) {
            sl(ara[i]);

            if(ara[i] & 1) odd.pb(i);
            else ev.pb(i);
        }

        while(ans.size() < n-1) {
            if(odd.size() >= 2) {
                ll p1 = odd.back();
                odd.pop_back();

                ll p2 = odd.back();
                odd.pop_back();

                ans.pb(mp(p1, p2));
            }
            else {
                ll p1 = ev.back();
                ev.pop_back();

                ll p2 = ev.back();
                ev.pop_back();

                ans.pb(mp(p1, p2));
            }
        }

        for(pll &p : ans)
            pf("%lld %lld\n", p.first, p.second);

        ans.clear(), odd.clear(), ev.clear();
    }

    return 0;
}