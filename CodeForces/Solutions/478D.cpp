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

const ll mod = 1e9 + 7;
ll r, g, tot, mxh, dp[2][200009];

int main()
{
    cin >> r >> g;
    tot = r + g;

    bool state = 0;
    dp[state][0] = 1;

    for1(h, 900) {

        state ^= 1;
        bool ok = 0;

        for(ll j = 0; j <= r; j++) {

            ll used = ((h-1) * h) / 2, guse = used - j;
            ll green = g - guse;

            dp[state][j] = 0;

            if(green >= h) {
                dp[state][j] += dp[state^1][j];
                if(dp[state][j] >= mod) dp[state][j] -= mod;
            }

            if(j - h >= 0) {
                dp[state][j] += dp[state^1][j-h];
                if(dp[state][j] >= mod) dp[state][j] -= mod;
            }

            //cout << h << "  " << j << "  " << dp[state][j] << endl;

            if(dp[state][j] != 0) mxh = h, ok = 1;
        }

        if(!ok) {
            state ^= 1;
            break;
        }
    }

    ll ans = 0;
    for(ll j = 0; j <= r; j++) {
        ans += dp[state][j];
        if(ans >= mod)
            ans -= mod;
    }

    cout << ans << EL;

    return 0;
}