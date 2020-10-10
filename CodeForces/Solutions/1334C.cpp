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

const ll sz = 3e5 + 10;
pll ara[sz];
ll pre[sz], dp[sz][2], n;

ll solve(ll pos, bool prv)
{
    if(pos > n)
        return 0;
    ll &ret = dp[pos][prv];
    if(ret != -1)
        return ret;

    ll rt = 0;
    if(prv) rt += max(ara[pos].first - ara[pos-1].second, 0LL);
    else rt += ara[pos].first;

    return ret = rt + solve(pos+1, 1);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n);

        for1(i, n) {
            sl(ara[i].first), sl(ara[i].second);
            pre[i] = 0;
            dp[i][0] = dp[i][1] = -1;
        }

        for(ll i = 2; i <= n; i++) {
            ll need = max(ara[i].first - ara[i-1].second, 0LL);
            pre[i] = pre[i-1] + need;
        }

        ll ans1 = ara[1].first + pre[n];
        for(ll i = 2; i <= n; i++) {
            ll rt = solve(i, 0);

            ll need = max(ara[1].first - ara[n].second, 0LL);
            if(i > 2) need += pre[i-1];

            ans1 = min(ans1, need + rt);
        }

        pf("%lld\n", ans1);
    }

    return 0;
}