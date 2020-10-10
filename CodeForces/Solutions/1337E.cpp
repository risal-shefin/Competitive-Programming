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

const ll sz = 3e3 + 10, mod = 998244353;
char s[sz], t[sz];
ll dp[sz][sz];

ll solve(ll l, ll r)
{
    if(l > r) return 1;
    ll &ret = dp[l][r];
    if(ret != -1)
        return ret;

    ll rt = 0, idx = r-l+1;
    if(s[idx] == t[r] || t[r] == '$')
        rt = (rt + solve(l, r-1) ) % mod;
    if(s[idx] == t[l] || t[l] == '$')
        rt = (rt + solve(l+1, r) ) % mod;

    return ret = rt;
}

int main()
{
    scanf("%s", s+1);
    scanf("%s", t+1);

    ll n = strlen(s+1), m = strlen(t+1);
    ll m2 = m;
    while(m2 < n) t[++m2] = '$';

    ms(dp, -1);
    ll tot = 0;

    for(ll i = m; i <= n; i++)
        tot = (tot + solve(1, i)) % mod;

    cout << tot << endl;

    return 0;
}