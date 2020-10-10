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

ll dp[12][(1<<10)], n, m;

char s[12][12], ans[12];

ll solve(ll pos, ll msk)
{
    if(pos > m) return 1;

    ll &ret = dp[pos][msk];
    if(ret != -1)
        return ret;

    for1(i, n) {
        ll now = 0;
        for1(j, n) {
            if(s[i][pos] != s[j][pos]) now |= (1 << j);
        }
        if( (msk & now) != 0)
            continue;

        now |= msk;
        ll got = solve(pos+1, now);
        if(got == 1) {
            ans[pos] = s[i][pos];
            //cout << pos << endl;
            return ret = 1;
        }
    }

    return ret = 0;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(m);

        for1(i, n) scanf("%s", s[i]+1);

        ms(dp, -1);
        ll got = solve(1, 0);
        //cout << got << endl;

        if(!got) pf("-1\n");
        else {
            ans[m+1] = '\0';
            pf("%s\n", ans+1);
        }
    }

    return 0;
}