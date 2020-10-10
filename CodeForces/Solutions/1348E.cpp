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

struct shrub {
    ll r, b;
} ara[509];

bool dp[sz][sz];

int main()
{
    ll n, k, tot = 0;
    cin >> n >> k;
    for1(i, n) {
        sl(ara[i].r), sl(ara[i].b);
        tot += ara[i].r + ara[i].b;
    }

    dp[0][0] = true;
    for1(i, n) {
        for0(j, k) {
            ll rest = ara[i].b % k;
            ll need = (j - rest) % k;
            if(need < 0) need += k;

            dp[i][j] = dp[i-1][need];

            for(ll b = 0; b <= min(k-1, ara[i].b); b++) {
                ll rest = (ara[i].b - b) % k;
                if(rest + ara[i].r < k)
                    continue;

                ll need = (j - b) % k;
                if(need < 0) need += k;

                dp[i][j] |= dp[i-1][need];
            }
        }
    }

    ll ans = 0;
    for0(i, k) {
        if(dp[n][i]) ans = max(ans, (tot - i) / k);
    }

    cout << ans << endl;

    return 0;
}