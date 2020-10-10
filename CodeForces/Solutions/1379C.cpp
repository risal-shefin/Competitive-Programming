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

const ll sz = 1e5 + 10;
pll ara[sz];
ll pre[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        sl(n), sl(m);

        for1(i, m) {
            sl(ara[i].first), sl(ara[i].second);
        }

        sort(ara+1, ara+m+1, greater<pll>());

        for1(i, m) pre[i] = ara[i].first + pre[i-1];

        ll ans = pre[min(n, m)];

        for1(i, m) {

            ll lo = 1, hi = min(n-2, m), pos = 0;

            if(ara[i].first >= ara[i].second)
                hi = min(n-1, m);

            while(lo <= hi) {
                ll mid = (lo+hi) >> 1;

                if(ara[mid].first >= ara[i].second) {
                    lo = mid + 1;
                    pos = mid;
                }
                else
                    hi = mid-1;
            }

            ll now = pre[pos];

            if(ara[i].first >= ara[i].second) now += (n-pos)*ara[i].second;
            else now += (ara[i].first + (n-pos-1)*ara[i].second);

            ans = max(ans, now);
        }

        pf("%lld\n", ans);
    }

    return 0;
}