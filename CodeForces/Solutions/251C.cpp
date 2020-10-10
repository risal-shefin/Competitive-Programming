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

const ll MAX_N = 4e5 + 10;
ll dp[MAX_N], a, b, k;

ll solve(ll num)
{
    if(num == 0)
        return 0;

    ll &ret = dp[num];
    if(ret != -1)
        return ret;

    ll nxt = num-1;
    for(ll i = 2; i <= k; i++) nxt = min(nxt, num - (num % i));

    return ret = 1 + solve(nxt);
}

int main()
{
    cin >> a >> b >> k;

    ll lcm = 2;
    for(ll i = 3; i <= k; i++) {
        lcm = (lcm * i) / __gcd(lcm, i);
    }

    ms(dp, -1);
    for0(i, lcm) dp[i] = solve(i);

    ll ans = 0, aBlock = a / lcm, bBlock = b / lcm;

    if(aBlock != bBlock) {

        ans += dp[a%lcm];

        ll diff = aBlock - bBlock;
        ans += diff;
        ans += (diff-1) * dp[lcm-1];

        a = (bBlock+1)*lcm - 1;
    }

    while(a > b) {

        ll nxt = a-1;

        for(ll i = 2; i <= k; i++) {

            ll nxt2 = a - (a % i);
            if(nxt2 >= b) nxt = min(nxt, nxt2);
        }

        ans++;
        a = nxt;
    }

    cout << ans << EL;

    return 0;
}