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

const ll sz = 205;
ll a[sz], b[sz], c[sz], dp[sz][sz][sz];

ll solve(ll ida, ll idb, ll idc)
{
    if((ida>0) + (idb>0) + (idc>0) < 2)
        return 0;

    ll &ret = dp[ida][idb][idc];
    if(ret != -1)
        return ret;

    ret = 0;
    if(ida > 0) {
        if(idb > 0) ret = max(ret, a[ida] * b[idb] + solve(ida-1, idb-1, idc));
        if(idc > 0) ret = max(ret, a[ida] * c[idc] + solve(ida-1, idb, idc-1));
    }
    if(idb>0 && idc> 0)
        ret = max(ret, b[idb]*c[idc] + solve(ida, idb-1, idc-1));

    return ret;
}

int main()
{
    ll r, g, bl;
    cin >> r >> g >> bl;

    for1(i, r) sl(a[i]);
    for1(i, g) sl(b[i]);
    for1(i, bl) sl(c[i]);

    sort(a+1, a+r+1);
    sort(b+1, b+g+1);
    sort(c+1, c+bl+1);

    ll ida = r, idb = g, idc = bl;

    ms(dp, -1);
    ll ans = solve(ida, idb, idc);

    pf("%lld\n", ans);

    return 0;
}