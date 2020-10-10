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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll exist[32];
ll dp[32], dg, tmp, d, m;

ll solve(ll pos)
{
    if(pos > dg)
        return 1 % m;

    ll &ret = dp[pos];
    if(ret != -1)
        return ret;

    ll rt = (exist[pos] * solve(pos+1)) % m;
    rt = (rt + solve(pos + 1)) % m;

    return ret = rt;
}

int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        sl(d), sl(m);

        dg = 0, tmp = d;
        while(tmp) {
            tmp /= 2;
            dg++;
        }

        for(ll i = 1; i < dg; i++)
            exist[i] = (1LL << i) - (1LL << (i-1));

        exist[dg] = d - (1LL << (dg-1)) + 1;

        ms(dp, -1);
        ll ans = (solve(1) - 1) % m;
        if(ans < 0) ans += m;

        pf("%lld\n", ans);
    }

    return 0;
}