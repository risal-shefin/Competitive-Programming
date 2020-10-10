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

const ll sz = 509;
ll n, m, b, mod;
ll dp[2][sz][sz], a[sz];

int main()
{
    sl(n), sl(m), sl(b), sl(mod);
    for1(i, n) sl(a[i]);

    ll row = 0;
    dp[row][0][0] = dp[row^1][0][0] = 1 % mod;

    for(ll i = 1; i <= n; i++) {
        row ^= 1;

        for(ll j = 1; j <= m; j++) {

            for(ll bug = 0; bug <= b; bug++) {

                dp[row][j][bug] = dp[row^1][j][bug];
                if(bug >= a[i])
                    dp[row][j][bug] += dp[row][j-1][bug-a[i]];

                if(dp[row][j][bug] >= mod) dp[row][j][bug] -= mod;
            }
        }
    }

    ll ans = 0;
    for(ll bug = 0; bug <= b; bug++) {
        ans += dp[row][m][bug];
        if(ans >= mod) ans -= mod;
    }

    cout << ans << endl;

    return 0;
}