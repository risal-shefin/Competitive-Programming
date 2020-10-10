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
#define inf (1LL << 61)
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
ll dp[sz], val[sz], c[sz];

struct info {
    ll val, col;
};

int main()
{
    ll n, q;
    cin >> n >> q;

    for1(i, n) sl(val[i]);
    for1(i, n) sl(c[i]);

    while(q--) {
        ll a, b, ans = 0;
        sl(a), sl(b);

        info mx1 = {0, 0}, mx2 = {0, 0};

        for1(i, n) dp[i] = -inf;

        for1(i, n) {

            ll col = c[i];

            if(dp[col] != -inf) dp[col] = max(dp[col], dp[col] + val[i]*a);

            if(mx1.col != col) dp[col] = max(dp[col], mx1.val + val[i]*b);
            else dp[col] = max(dp[col], mx2.val + val[i]*b);

            if(dp[col] >= mx1.val) {

                if(col != mx1.col) mx2 = mx1;

                mx1 = {dp[col], col};
            }
            else if(dp[col] >= mx2.val && mx1.col != col)
                mx2 = {dp[col], col};

            ans = max(ans, dp[col]);
        }

        pf("%lld\n", ans);
    }

    return 0;
}