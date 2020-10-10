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

const ll sz = 1e6 + 10, mod = 1e9 + 7;
ll p[sz], n, x, cnt[sz];
unordered_set <int> exist;

ll fastPow(ll x, ll n)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret*x) % mod;
        x = (x*x) % mod;
        n >>= 1;
    }
    return ret % mod;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(x);
        for1(i, n) sl(p[i]);

        if(x == 1) {
            if(n & 1) pf("1\n");
            else pf("0\n");
            continue;
        }

        sort(p+1, p+n+1);
        ll ptr = n, ptr2, ans = 0;
        while(ptr >= 1) {
            ll rhs = p[ptr];

            ptr2 = ptr-1;
            while(ptr2 >= 1) {
                ll lhs = p[ptr2];
                cnt[lhs]++;
                exist.insert(lhs);

                while(cnt[lhs] == x) {
                    cnt[lhs] = 0;
                    exist.erase(lhs);

                    lhs++;
                    cnt[lhs]++;
                    exist.insert(lhs);
                }

                if(cnt[rhs] > 0) {
                    cnt[rhs] = 0;
                    exist.erase(rhs);
                    break;
                }

                ptr2--;
            }

            if(ptr2 < 1) {
                ll lval = 0;
                for(const int &pwr : exist) lval = (lval + cnt[pwr] * fastPow(x, pwr)) % mod;
                ll rval = fastPow(x, rhs);

                ans = rval - lval;
                if(ans < 0) ans += mod;
                break;
            }

            ptr = ptr2 - 1;
        }

        pf("%lld\n", ans);

        for(const int &pwr : exist) cnt[pwr] = 0;
        exist.clear();
    }

    return 0;
}