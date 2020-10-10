
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
ll dp[sz], ara[sz];
vector <int> dv[sz];

int main()
{
    for(ll i = 2; i < sz; i++) {
        for(ll j = i; j < sz; j += i)
            dv[j].pb(i);
    }

    ll n;
    cin >> n;

    for1(i, n) sl(ara[i]);

    ll ans = 1;
    rep1(i, n) {
        ll mx = 0;
        for(ll j = 0; j < dv[ ara[i] ].size(); j++) {
            ll num = dv[ara[i]][j];
            mx = max(mx, dp[num]);
        }

        for(ll j = 0; j < dv[ ara[i] ].size(); j++) {
            ll num = dv[ara[i]][j];

            dp[num] = max(dp[num], mx+1);
            ans = max(ans, dp[num]);
        }
    }

    cout << ans << EL;

    return 0;
}