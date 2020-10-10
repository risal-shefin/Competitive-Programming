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

ll n, odd, ara[105], rodd, reven, even;
ll dp[109][109][209][2];
ll blank[109];

ll solve(ll pos, ll od, ll com, ll prv)
{
    if(pos > n)
        return 0;

    ll &ret = dp[pos][od][com][prv];
    if(ret != -1)
        return ret;

    if(ara[pos] != 0) {
//        if(pos == 2)
//            cout << ( (ara[pos] & 1) != prv) << endl;
        return ret = ( (ara[pos] & 1) != prv) + solve(pos+1, od, com, ara[pos] & 1);
    }

    ll rt = inf, ev = blank[pos-1] - od;
    if(pos == 1) {
        if(odd + od + 1 <= rodd)
            rt = solve(pos+1, od+1, com, 1);
        if(even + ev + 1 <= reven)
            rt = min(rt, solve(pos + 1, od, com, 0));
    }
    else {

        if(odd + od + 1 <= rodd) {
            rt = (prv==0) + solve(pos + 1, od+1, com + prv==0, 1);
        }
        if(even + ev + 1 <= reven)
            rt = min(rt, (prv==1) + solve(pos + 1, od, com + prv==1, 0));
    }

    return ret = rt;
}

int main()

{
    ll ase = 0;
    cin >> n;
    for1(i, n) {
        sl(ara[i]);
        if(ara[i] == 0) {
            blank[i] = 1;
            continue;
        }

        ase++;
        if(ara[i] % 2 == 0)
            even++;
    }

    for1(i, n)
        blank[i] += blank[i-1];

    odd = ase - even;
    rodd = n / 2, reven = n / 2;
    if(n & 1)
        rodd++;

    ms(dp, -1);
    ll ans = solve(1, 0, 0, ara[1] & 1);

    cout << ans << endl;

    return 0;
}