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

const ll mod = 1e8;
ll dp[105][105][15][15], lim1, lim2;

ll solve(ll n1, ll n2, ll k1, ll k2)
{
    if(n1 == 0 && n2 == 0)
        return 1;

    ll &ret = dp[n1][n2][k1][k2];
    if(ret != -1)
        return ret;

    ret = 0;
    if(n1 > 0 && k1 > 0) {
        ret += solve(n1-1, n2, k1-1, lim2);
        if(ret >= mod) ret -= mod;
    }
    if(n2 > 0 && k2 > 0) {
        ret += solve(n1, n2-1, lim1, k2-1);
        if(ret >= mod) ret -= mod;
    }

    return ret;
}

int main()
{
    ms(dp, -1);

    ll n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    lim1 = k1, lim2 = k2;
    cout << solve(n1, n2, k1, k2) << EL;

    return 0;
}