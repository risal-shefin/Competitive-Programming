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

ll dp[2][2][2][2][32];
vector <ll> leftNum, num;

ll solve(ll isBig1, ll isSmall1, ll isBig2, ll isSmall2, ll pos)
{
    if(pos == num.size())
        return 1;
    ll &ret = dp[isBig1][isSmall1][isBig2][isSmall2][pos];
    if(ret != -1)
        return ret;

    ll start1, lim1, start2, lim2, pos2 = pos;

    if(isBig1) start1 = 0;
    else    start1 = leftNum[pos2];

    if(isSmall1) lim1 = 1;
    else    lim1 = num[pos2];

    if(isBig2) start2 = 0;
    else    start2 = leftNum[pos2];

    if(isSmall2) lim2 = 1;
    else    lim2 = num[pos2];

    ll rt = 0;
    for(ll d = start1; d <= lim1; d++) {
        for(ll i = start2; i <= lim2; i++) {
            if(d == 1 && i == 1) continue;
            rt += solve(isBig1 | d > leftNum[pos2], isSmall1 | d < num[pos2], isBig2 | i > leftNum[pos2], isSmall2 | i < num[pos2], pos + 1);
        }
    }

    return ret = rt;
}

ll calc(ll l, ll r)
{
    if(r == 0) return 1;

    ll tmp = r;
    num.clear();
    while(tmp) {
        num.pb(tmp % 2);
        tmp /= 2;
    }
    reverse(all(num));

    tmp = l;
    leftNum.clear();
    while(tmp) {
        leftNum.pb(tmp % 2);
        tmp /= 2;
    }
    while(leftNum.size() < num.size()) leftNum.pb(0);
    reverse(all(leftNum));

    return solve(0, 0, 0, 0, 0);
}


int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ms(dp, -1);

        ll l, r, ans = 0;
        sl(l), sl(r);

        ans += calc(l, r);

        pf("%lld\n", ans);
    }

    return 0;
}